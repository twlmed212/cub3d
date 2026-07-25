/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 06:29:20 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/23 07:39:47 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	*check_help(char *str, size_t pos)
{
	if (ft_strlen(str) <= pos || str[pos] == '1' || ft_isspace(str[pos]))
		return (NULL);
	return ((void *)1);
}

void	*ft_space_check(char **table, int j, int *i)
{
	int	tmp;
	int	len;

	len = count_element(table);
	while (table[j][*i] && ft_isspace(table[j][*i]))
	{
		tmp = 0;
		while (j - tmp && (ft_strlen(table[j - tmp]) <= (size_t)(*i)
			|| ft_isspace(table[j - tmp][*i])))
		{
			tmp++;
			if (check_help(table[j - tmp], *i))
				return (error_space("spaces are not surround by walls"), NULL);
		}
		tmp = 0;
		while (len - 1 > tmp + j && (ft_strlen(table[j + tmp]) <= (size_t)(*i)
			|| ft_isspace(table[j + tmp][*i])))
		{
			tmp++;
			if (check_help(table[tmp + j], *i))
				return (error_space("spaces are not surround by walls"), NULL);
		}
		(*i)++;
	}
	return ((void *)1);
}

void	*ft_walls(char **map, int row)
{
	int	i;

	i = 0;
	while (map[row][i])
	{
		if (!ft_space_check(map, row, &i))
			return (NULL);
		if (map[row][i] != '1')
		{
			printf("Error : Invalid wall \n");
			return (NULL);
		}
		while (map[row][i] == '1')
			i++;
	}
	return ((void *)1);
}

static void	*ft_side_walls(char **map)
{
	int	j;
	int	i;

	j = 1;
	while (map[j + 1])
	{
		i = 0;
		if (map[j][0] == '\n')
			return (error_space("Invalid wall"), NULL);
		if (!ft_space_check(map, j, &i))
			return (NULL);
		if (map[j][i] != '1')
			return (error_space("Invalid wall"), NULL);
		i = ft_strlen(map[j]) - 1;
		while (i >= 0 && ft_isspace(map[j][i]))
			i--;
		if (map[j][i] != '1')
			return (error_space("Invalid wall"), NULL);
		if (!ft_space_check(map, j, &i))
			return (NULL);
		j++;
	}
	return ((void *)1);
}

void	*check_map_walls(char **map)
{
	if (con_table(map) <= 2)
	{
		printf("Error\nMap must have at least 3 rows\n");
		return (NULL);
	}
	if (!ft_walls(map, 0))
		return (NULL);
	if (!ft_walls(map, con_table(map) - 1))
		return (NULL);
	if (!ft_side_walls(map))
		return (NULL);
	return ((void *)1);
}
