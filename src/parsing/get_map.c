/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 06:29:37 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/23 07:23:09 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	*check_line(int fd)
{
	char	*line;
	int		flag;

	flag = 0;
	line = get_next_line(fd, &flag);
	while (line)
	{
		remove_newline(line);
		if (!*line)
			return ((void *)1);
		if (*line != '\n' && !ft_check_content(line))
			return (ft_putstr_fd("Error\nThe map is sperited\n", 2), NULL);
		line = get_next_line(fd, &flag);
	}
	return ((void *)1);
}

size_t	con_table(char **elem)
{
	size_t	i;

	if (!elem)
		return (0);
	i = 0;
	while (elem[i])
		i++;
	return (i);
}

void	*add_map(char **line, char *str)
{
	char	**lines;
	int		i;

	lines = ft_malloc((con_table(line) + 2) * sizeof(char *));
	if (!lines)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		lines[i] = line[i];
		i++;
	}
	lines[i++] = str;
	lines[i] = NULL;
	return (lines);
}

static char	**fill_map(t_cub *cub, int *flag)
{
	char	*line;
	char	**lines;

	lines = NULL;
	line = ft_find_data(cub->fd, flag);
	if (!line && *flag == 1)
		print_error_map("map not found");
	while (line && *line && !ft_check_content(line) && *line != '\n')
	{
		lines = add_map(lines, line);
		if (!lines)
			return (NULL);
		line = get_next_line(cub->fd, flag);
		if (line)
			remove_newline(line);
	}
	return (lines);
}

void	*get_map(t_cub *cub)
{
	char	**lines;
	int		flag;

	flag = 0;
	lines = fill_map(cub, &flag);
	if (!lines)
		return (NULL);
	if (!check_line(cub->fd))
		return (NULL);
	return (ft_check_map(cub, lines));
}
