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

void	*ft_check_map(t_cub *cub, char **map)
{
	if (!check_map_walls(map))
		return (NULL);
	if (!ft_map_elements(cub, map))
		return (NULL);
	cub->map = map;
	close(cub->fd);
	cub->fd = -1;
	return ((void *)1);
}
