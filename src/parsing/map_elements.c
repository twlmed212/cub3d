/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 06:29:41 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/25 11:23:16 by mtawil           ###   ########.fr       */
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
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}

static void	*ft_parse_elem(t_cub *game, char **map, int y, int *x)
{
	int	type;

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
		if (!space_run_ok(map[y], *x))
			return (print_pars_elem("spaces are not surronded by walls"),
				NULL);
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
		ft_putstr_fd("Error\nNo player found\n", 2);
		return (NULL);
	}
	return ((void *)1);
}
