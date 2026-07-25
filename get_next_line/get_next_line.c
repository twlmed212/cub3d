/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:54:03 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/25 10:48:59 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

ssize_t	ft_indexchr(char *s, int c)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*extract_line(char **str)
{
	char	*line;
	char	*temp;
	ssize_t	line_pos;

	temp = NULL;
	line_pos = ft_indexchr(*str, '\n');
	if (line_pos >= 0)
	{
		line = ft_substr(*str, 0, line_pos + 1);
		temp = ft_substr(*str, line_pos + 1, ft_strlen(*str) - line_pos - 1);
		*str = temp;
	}
	else
	{
		line = ft_strdup(*str);
		*str = NULL;
	}
	return (line);
}

static char	*read_line(int fd, char *new, char *buff)
{
	char	*temp;
	ssize_t	n;

	buff[0] = '\0';
	while (!ft_strchr(buff, '\n'))
	{
		n = read(fd, buff, (size_t)BUFFER_SIZE);
		if (n == -1)
			return (free(buff), NULL);
		if (n == 0)
			break ;
		buff[n] = '\0';
		if (!new)
			new = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(new, buff);
			new = temp;
		}
	}
	return (free(buff), new);
}

char	*get_next_line(int fd, int *flag)
{
	static char	*new = NULL;
	char		*line;
	char		*buff;

	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
	{
		printf("Malloc failed");
		new = NULL;
		return (NULL);
	}
	new = read_line(fd, new, buff);
	if (!new || *new == '\0')
	{
		*flag = 1;
		new = NULL;
		return (NULL);
	}
	line = extract_line(&new);
	if (!line)
	{
		printf("Malloc failed");
		return (NULL);
	}
	return (line);
}
