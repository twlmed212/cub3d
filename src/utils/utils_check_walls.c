/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 07:04:20 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/25 13:27:54 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	space_run_ok(char *row, int x)
{
	int	l;
	int	f;

	l = x;
	f = 0;
	while (row[l] && ft_isspace(row[l]))
	{
		f = 1;
		l++;
	}
	if (row[l] && row[l] != '1' && f == 1)
		return (0);
	return (1);
}

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
