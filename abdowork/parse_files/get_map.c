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

#include "../cub3d.h"

static void	*check_line(int fd)
{
	char	*line;
	int		flag;

	line = NULL;
	flag = 0;
	while (1)
	{
		remove_newline(line);
		line = get_next_line(fd, &flag);
		if (!line)
		{
			if (flag == 1)
				break ;
			return (NULL);
		}
		if (!*line)
		{
			free(line);
			line = NULL;
			break ;
		}
		if (*line != '\n' && !ft_check_content(line))
		{
			printf("The map is sperited\n");
			line = NULL;
			return (NULL);
		}
		free(line);
		line = NULL;
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

	lines = malloc((con_table(line) + 2) * sizeof(char *));
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
	free(line);
	return (lines);
}

void	print_error_map(char *message)
{
	printf("Error\n%s\n", message);
	exit(1);
}

void	*get_map(t_cub *cub)
{
	char	*line;
	char	**lines;
	int		flag;

	flag = 0;
	line = ft_find_data(cub->fd, &flag);
	if (!line && flag == 1)
		print_error_map("map not found");
	while (1)
	{
		if (!line)
			return (NULL);
		if (!*line || ft_check_content(line) || *line == '\n')
			break ;
		lines = add_map(lines, line);
		if (!lines)
			return (NULL);
		line = get_next_line(cub->fd, &flag);
		if (!line)
		{
			if (flag == 1)
				break ;
			return (NULL);
		}
		remove_newline(line);
	}
	if (!check_line(cub->fd))
		return (free(line), NULL);
	return (free(line), ft_check_map(cub, lines));
}
