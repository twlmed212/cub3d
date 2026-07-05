/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 18:23:56 by mtawil            #+#    #+#             */
/*   Updated: 2026/06/30 18:24:09 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


int close_window(void *param)
{
	t_cub *game;

	game = (t_cub *)param;
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int key_press(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		close_window(param);
	else if (keycode == KEY_LEFT)
		printf("Left key pressed\n");
	else if (keycode == KEY_RIGHT)
		printf("Right key pressed\n");
	return (0);
}