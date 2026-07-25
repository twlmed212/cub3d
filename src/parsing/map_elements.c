/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 06:29:41 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/23 07:39:13 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_is_map_char(char c)
{
	if (c == '1' || c == '0')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	return (0);
}

static int	ft_set_player(t_cub *game, int y, int x)
{
	if (game->player.x != 0 || game->player.y != 0)
		return (1);
	game->player.y = y;
	game->player.x = x;
	return (0);
}

void	print_pars_elem(char *message)
{
	printf("Error\n%s\n", message);
}

static void	*ft_parse_elem(t_cub *game, char **map, int y, int *x)
{
	int	type;
	int	l;
	int	f;

	while (map[y][*x])
	{
		type = ft_is_map_char(map[y][*x]);
		if (!type && !ft_isspace(map[y][*x]))
			return (print_pars_elem("Invalid map element"), NULL);
		if (ft_isspace(map[y][*x]))
			return ((void *)1);
		if (type == 2 && ft_set_player(game, y, *x))
			return (print_pars_elem("More than one player"), NULL);
		(*x)++;
		if (map[y][*x] && map[y][*x - 1] != '1' && ft_isspace(map[y][*x]))
			return (print_pars_elem("spaces are not surronded by walls"),
				NULL);
		l = *x;
		f = 0;
		while (map[y][l] && ft_isspace(map[y][(l)++]))
			f = 1;
		if (map[y][l] && map[y][l] != '1' && f == 1)
			return (print_pars_elem("spaces are not surronded by walls"), NULL);
	}
	return ((void *)1);
}

void	*ft_map_elements(t_cub *game, char **map)
{
	int	y;
	int	x;

	y = 1;
	while (map[y + 1])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_space_check(map, y, &x))
				return (NULL);
			if (!ft_parse_elem(game, map, y, &x))
				return (NULL);
		}
		y++;
	}
	if (game->player.x == 0 && game->player.y == 0)
	{
		printf("No player found\n");
		return (NULL);
	}
	return ((void *)1);
}
