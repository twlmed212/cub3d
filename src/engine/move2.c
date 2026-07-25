/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:28:42 by mtawil            #+#    #+#             */
/*   Updated: 2026/07/25 13:29:04 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wall_point(t_cub *game, double x, double y)
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

int	touch_wall(t_cub *game, double x, double y)
{
	if (is_wall_point(game, x - 0.2, y - 0.2)
		|| is_wall_point(game, x + 0.2, y - 0.2)
		|| is_wall_point(game, x - 0.2, y + 0.2)
		|| is_wall_point(game, x + 0.2, y + 0.2))
		return (1);
	return (0);
}