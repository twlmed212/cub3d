/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 10:00:00 by mtawil            #+#    #+#             */
/*   Updated: 2026/07/14 09:41:15 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	touch_wall(t_cub *game, double x, double y)
{
	int	mx;
	int	my;
	int	h;

	mx = (int)x;
	my = (int)y;
	if (my < 0 || mx < 0 || !game->map)
		return (1);
	h = 0;
	while (game->map[h])
		h++;
	if (my >= h)
		return (1);
	if (mx >= (int)ft_strlen(game->map[my]))
		return (1);
	return (game->map[my][mx] != '0');
}

// check each axe alone so we slide on walls insted of stoping
static void	move_player(t_cub *game, double nx, double ny)
{
	if (!touch_wall(game, nx, game->player.y))
		game->player.x = nx;
	if (!touch_wall(game, game->player.x, ny))
		game->player.y = ny;
}

void	walk(t_cub *game, int d)
{
	double	nx;
	double	ny;

	nx = game->player.x + game->player.dir_x * MOVE_SPEED * d;
	ny = game->player.y + game->player.dir_y * MOVE_SPEED * d;
	move_player(game, nx, ny);
}

void	walk_sideways(t_cub *game, int d)
{
	double	nx;
	double	ny;

	nx = game->player.x + game->player.plane_x * MOVE_SPEED * d;
	ny = game->player.y + game->player.plane_y * MOVE_SPEED * d;
	move_player(game, nx, ny);
}

// rotation matrix, dont forget plane need to rotate too
void	rotate(t_cub *game, double a)
{
	double	old_dx;
	double	old_px;

	old_dx = game->player.dir_x;
	game->player.dir_x = old_dx * cos(a) - game->player.dir_y * sin(a);
	game->player.dir_y = old_dx * sin(a) + game->player.dir_y * cos(a);
	old_px = game->player.plane_x;
	game->player.plane_x = old_px * cos(a) - game->player.plane_y * sin(a);
	game->player.plane_y = old_px * sin(a) + game->player.plane_y * cos(a);
}
