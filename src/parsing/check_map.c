/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 06:29:13 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/23 08:15:02 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_tab(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_elements(char ***e)
{
	int	i;

	i = 0;
	if (!e)
		return ;
	while (e[i])
		ft_free_tab(e[i++]);
	free(e);
}

void	*ft_check_map(t_cub *cub, char **map)
{
	if (!check_map_walls(map))
		return (ft_free_tab(map), NULL);
	if (!ft_map_elements(cub, map))
		return (ft_free_tab(map), NULL);
	cub->map = map;
	close(cub->fd);
	cub->fd = -1;
	return ((void *)1);
}
