/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 06:29:24 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/23 07:39:56 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_get_color(int r, int g, int b)
{
	return (255 << 24 | r << 16 | g << 8 | b);
}

void	check_color(char **element, t_cub *cub, char *id)
{
	char			**rgb;
	unsigned char	*str;

	if (!element || !element[0] || !element[1])
		print_error("Missing color value for ", id);
	if (ft_strcmp(element[0], id) != 0)
		print_error("Invalid color identifier ", NULL);
	if (element[2])
		print_error("Too many arguments for ", id);
	clean_path(element[1]);
	if (!some_checks(element[1]))
		print_error("Invalid color format for ", id);
	rgb = ft_split(element[1], ',');
	if (!rgb)
		print_error("Malloc failed", NULL);
	if (count_element(rgb) != 3)
		print_error("RGB must contain exactly 3 values", NULL);
	str = check_rgb_values(rgb);
	if (*id == 'F')
		cub->floor_color = ft_get_color(str[0], str[1], str[2]);
	else
		cub->ceiling_color = ft_get_color(str[0], str[1], str[2]);
	free(str);
	ft_free_tab(rgb);
}

void	check_elements(t_cub *cub, char ***elements)
{
	int	i;

	i = 0;
	while (elements[i])
	{
		if (ft_strncmp(elements[i][0], "NO", 2) == 0)
			check_texture(elements[i], "NO");
		else if (ft_strncmp(elements[i][0], "SO", 2) == 0)
			check_texture(elements[i], "SO");
		else if (ft_strncmp(elements[i][0], "WE", 2) == 0)
			check_texture(elements[i], "WE");
		else if (ft_strncmp(elements[i][0], "EA", 2) == 0)
			check_texture(elements[i], "EA");
		else if (ft_strncmp(elements[i][0], "F", 1) == 0)
			check_color(elements[i], cub, "F");
		else if (ft_strncmp(elements[i][0], "C", 1) == 0)
			check_color(elements[i], cub, "C");
		else
		{
			printf("Error\nInvalid element identifier or wrong extension: %s\n",
				elements[i][0]);
			exit(1);
		}
		i++;
	}
}

void	*ft_get_elements(t_cub *cub)
{
	int		i;
	char	*line;
	char	***elements;
	int		flag;

	flag = 0;
	cub->elem = malloc(sizeof(char *) * 7);
	if (!(cub->elem))
		return (NULL);
	i = 0;
	while (i < 6)
	{
		line = ft_find_data(cub->fd, &flag);
		if (!line && flag == 1)
			return (print_error_get_elem("map not found"), NULL);
		if (!line)
			return (print_error_get_elem("Malloc failed"), NULL);
		cub->elem[i++] = line;
		cub->elem[i] = NULL;
	}
	elements = split_elements(cub->elem);
	if (!elements)
		return (print_error_get_elem("Malloc failed"), NULL);
	check_elements(cub, elements);
	return (cub);
}
