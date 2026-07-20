/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:35:00 by mtawil            #+#    #+#             */
/*   Updated: 2026/07/20 11:13:13 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_wall(t_cub *game, int x, int y)
{
	if (y < 0 || x < 0 || !game->map[y])
		return (1);
	if (x >= (int)ft_strlen(game->map[y]))
		return (1);
	return (game->map[y][x] == '1');
}

static void	init_ray(t_cub *game, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2.0 * x / WIN_WIDTH - 1;
	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;
	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	init_step_x(t_cub *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.x)
			* ray->delta_dist_x;
	}
}

static void	init_step_y(t_cub *game, t_ray *ray)
{
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.y)
			* ray->delta_dist_y;
	}
}


void	cast_ray(t_cub *game, t_ray *ray, int x)
{
	init_ray(game, ray, x);
	init_step_x(game, ray);
	init_step_y(game, ray);
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (is_wall(game, ray->map_x, ray->map_y))
			break ;
	}
	if (ray->side == 0)
		ray->cam_distance = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->cam_distance = ray->side_dist_y - ray->delta_dist_y;
}
