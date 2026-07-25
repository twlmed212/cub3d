/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 06:29:45 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/23 07:28:36 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_content(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	*ft_find_data(int fd, int *flag)
{
	char	*str;

	while (1)
	{
		str = get_next_line(fd, flag);
		if (!str && *flag == 1)
			break ;
		remove_newline(str);
		if (!str)
			return (NULL);
		if (!ft_check_content(str) && *str != '\n')
			break ;
		free(str);
	}
	return (str);
}

size_t	count_element(char **str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_xpm(char *file)
{
	int	len;

	if (!file)
		return (0);
	len = ft_strlen(file);
	if (len < 4 || *(file + len - 5) == '/')
		return (0);
	if (ft_strncmp(file + len - 4, ".xpm", 4) != 0)
		return (0);
	return (1);
}

void	clean_path(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'))
		str[i--] = '\0';
}
