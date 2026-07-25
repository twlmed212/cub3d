/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:35:32 by mtawil            #+#    #+#             */
/*   Updated: 2026/06/29 14:35:33 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_engine(t_cub *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nmlx init failed\n", 2);
		free_grabage();
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Mok3ab3D");
	if (!game->win)
	{
		ft_putstr_fd("Error\nmlx new window failed\n", 2);
		free_grabage();
		exit(1);
	}
	game->img.ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img.ptr)
	{
		ft_putstr_fd("Error\nmlx new image failed\n", 2);
		free_grabage();
		exit(1);
	}
	game->img.data = mlx_get_data_addr(game->img.ptr, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
}
