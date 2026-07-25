/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_check_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 07:04:20 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/23 07:29:16 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	*check_help(char *str, size_t pos)
{
	if (ft_strlen(str) <= pos || str[pos] == '1' || ft_isspace(str[pos]))
		return (NULL);
	return ((void *)1);
}

int	check_down(char **map, int j, int i)
{
	int	tmp;
	int	len;

	len = count_element(map);
	tmp = 0;
	while (j + tmp < len)
	{
		if (!map[j + tmp])
			break ;
		if (ft_strlen(map[j + tmp]) > (size_t)i && !ft_isspace(map[j + tmp][i]))
			return (1);
		tmp++;
		if (j + tmp >= len)
			break ;
		if (check_help(map[j + tmp], i))
			return (0);
	}
	return (0);
}

int	check_up(char **map, int j, int i)
{
	int	tmp;

	tmp = 0;
	while (j - tmp >= 0)
	{
		if (!map[j - tmp])
			break ;
		if (ft_strlen(map[j - tmp]) > (size_t)i && !ft_isspace(map[j - tmp][i]))
			return (1);
		tmp++;
		if (j - tmp < 0)
			return (0);
		if (check_help(map[j - tmp], i))
			return (0);
	}
	return (0);
}
