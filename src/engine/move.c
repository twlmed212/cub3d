/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 10:00:00 by mtawil            #+#    #+#             */
/*   Updated: 2026/07/25 13:28:52 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
