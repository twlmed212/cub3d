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

static int	count_id(char ***e, char *id)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (e[++i])
		if (!ft_strcmp(e[i][0], id))
			c++;
	return (c);
}

int	valid_ids(char ***e)
{
	char	*ids[6];
	int		i;

	ids[0] = "NO";
	ids[1] = "SO";
	ids[2] = "WE";
	ids[3] = "EA";
	ids[4] = "F";
	ids[5] = "C";
	i = -1;
	while (++i < 6)
		if (count_id(e, ids[i]) != 1)
			return (0);
	return (1);
}
