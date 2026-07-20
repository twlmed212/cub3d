/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 18:23:56 by mtawil            #+#    #+#             */
/*   Updated: 2026/07/14 09:41:15 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_textures(t_cub *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->tex[i].ptr)
			mlx_destroy_image(game->mlx, game->tex[i].ptr);
		i++;
	}
}

int	close_window(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	free_textures(game);
	if (game->img.ptr)
		mlx_destroy_image(game->mlx, game->img.ptr);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_tab(game->map);
	ft_free_tab(game->elem);
	free(game);
	exit(0);
}

int	key_press(int keycode, void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	if (keycode == KEY_ESC)
		close_window(param);
	else if (keycode == KEY_W)
		walk(game, 1);
	else if (keycode == KEY_S)
		walk(game, -1);
	else if (keycode == KEY_A)
		walk_sideways(game, -1);
	else if (keycode == KEY_D)
		walk_sideways(game, 1);
	else if (keycode == KEY_LEFT)
		rotate(game, -ROT_SPEED);
	else if (keycode == KEY_RIGHT)
		rotate(game, ROT_SPEED);
	return (0);
}
