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

// look in the parsed elem lines ("NO path", "SO path"..) and give back the path
static char	*find_path(t_cub *game, char *id)
{
	int		i;
	char	**sp;
	char	*path;

	i = 0;
	path = NULL;
	while (game->elem[i])
	{
		sp = ft_split(game->elem[i], ' ');
		if (sp && sp[0] && sp[1] && !ft_strcmp(sp[0], id))
			path = ft_strdup(sp[1]);
		ft_free_tab(sp);
		if (path)
			return (path);
		i++;
	}
	return (NULL);
}

static void	load_one(t_cub *game, t_tex *t, char *path)
{
	if (!path)
	{
		printf("Error\ntexture path missing\n");
		exit(1);
	}
	t->ptr = mlx_xpm_file_to_image(game->mlx, path, &t->width, &t->height);
	free(path);
	if (!t->ptr)
	{
		printf("Error\nfailed to load texture\n");
		exit(1);
	}
	t->data = mlx_get_data_addr(t->ptr, &t->bpp, &t->line_len, &t->endian);
}

// 0 = NO, 1 = SO, 2 = WE, 3 = EA .. paths come from abdo parsing now
void	init_textures(t_cub *game)
{
	load_one(game, &game->tex[0], find_path(game, "NO"));
	load_one(game, &game->tex[1], find_path(game, "SO"));
	load_one(game, &game->tex[2], find_path(game, "WE"));
	load_one(game, &game->tex[3], find_path(game, "EA"));
}
