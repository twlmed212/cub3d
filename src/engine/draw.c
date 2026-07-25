/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 11:10:00 by mtawil            #+#    #+#             */
/*   Updated: 2026/07/25 13:27:38 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	pick_tex(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (2);
		return (3);
	}
	if (ray->ray_dir_y > 0)
		return (0);
	return (1);
}

static int	tex_column(t_cub *game, t_ray *ray, t_tex *t)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->player.y + ray->cam_distance * ray->ray_dir_y;
	else
		wall_x = game->player.x + ray->cam_distance * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * t->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		tex_x = t->width - tex_x - 1;
	return (tex_x);
}

static int	tex_color(t_tex *tex, int tex_x, int tex_y)
{
	char	*px;

	if (!tex || !tex->data || tex->width <= 0 || tex->height <= 0)
		return (0);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	px = tex->data + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
	return (*(unsigned int *)px);
}

void	calc_wall(t_ray *ray)
{
	if (ray->cam_distance < 1e-4)
		ray->cam_distance = 1e-4;
	ray->line_h = (int)(WIN_HEIGHT / ray->cam_distance);
	if (ray->line_h == 0)
		ray->line_h = 1;
	ray->draw_start = -ray->line_h / 2 + WIN_HEIGHT / 2;
	ray->draw_end = ray->line_h / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_start >= WIN_HEIGHT)
		ray->draw_start = WIN_HEIGHT - 1;
	if (ray->draw_end < 0)
		ray->draw_end = 0;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	draw_column(t_cub *game, t_ray *ray, int x)
{
	t_tex	*wall_tex;
	double	step;
	double	tpos;
	int		y;
	int		tx;

	wall_tex = &game->tex[pick_tex(ray)];
	tx = tex_column(game, ray, wall_tex);
	step = (double)wall_tex->height / ray->line_h;
	tpos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_h / 2) * step;
	y = -1;
	while (++y < ray->draw_start)
		my_pixel_put(&game->img, x, y, game->ceiling_color);
	while (y <= ray->draw_end)
	{
		my_pixel_put(&game->img, x, y++, tex_color(wall_tex, tx, (int)tpos));
		tpos += step;
	}
	while (y < WIN_HEIGHT)
		my_pixel_put(&game->img, x, y++, game->floor_color);
}
