/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 11:00:00 by mtawil            #+#    #+#             */
/*   Updated: 2026/07/20 11:09:32 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	load_one(t_cub *game, t_tex *t, char *path)
{
	t->ptr = mlx_xpm_file_to_image(game->mlx, path, &t->width, &t->height);
	if (!t->ptr)
	{
		printf("Error\nfailed to load texture %s\n", path);
		exit(1);
	}
	t->data = mlx_get_data_addr(t->ptr, &t->bpp, &t->line_len, &t->endian);
}

// 0 = NO, 1 = SO, 2 = WE, 3 = EA TODO: Remove this hardcoded things
void	init_textures(t_cub *game)
{
	load_one(game, &game->tex[0], "xpm/Akatsuki.xpm");
	load_one(game, &game->tex[1], "xpm/mangigue.xpm");
	load_one(game, &game->tex[2], "xpm/tsakiumi.xpm");
	load_one(game, &game->tex[3], "xpm/uchiha.xpm");
}
