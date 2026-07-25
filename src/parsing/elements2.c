/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 06:29:24 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/25 10:22:02 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_one(t_cub *cub, char **e)
{
	if (ft_strncmp(e[0], "NO", 2) == 0)
		check_texture(e, "NO");
	else if (ft_strncmp(e[0], "SO", 2) == 0)
		check_texture(e, "SO");
	else if (ft_strncmp(e[0], "WE", 2) == 0)
		check_texture(e, "WE");
	else if (ft_strncmp(e[0], "EA", 2) == 0)
		check_texture(e, "EA");
	else if (ft_strncmp(e[0], "F", 1) == 0)
		check_color(e, cub, "F");
	else if (ft_strncmp(e[0], "C", 1) == 0)
		check_color(e, cub, "C");
	else
		print_error("Invalid element identifier", NULL);
}

void	check_elements(t_cub *cub, char ***elements)
{
	int	i;

	i = 0;
	while (elements[i])
	{
		check_one(cub, elements[i]);
		i++;
	}
}
