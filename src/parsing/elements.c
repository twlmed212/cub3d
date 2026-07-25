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
}

static int	read_six(t_cub *cub)
{
	int		i;
	char	*line;
	int		flag;

	flag = 0;
	i = 0;
	while (i < 6)
	{
		line = ft_find_data(cub->fd, &flag);
		if (!line && flag == 1)
			return (print_error_get_elem("map not found"), 0);
		if (!line)
			return (print_error_get_elem("Malloc failed"), 0);
		cub->elem[i++] = line;
		cub->elem[i] = NULL;
	}
	return (1);
}

void	*ft_get_elements(t_cub *cub)
{
	char	***elements;

	cub->elem = ft_malloc(sizeof(char *) * 7);
	if (!(cub->elem))
		return (NULL);
	cub->elem[0] = NULL;
	if (!read_six(cub))
		return (NULL);
	elements = split_elements(cub->elem);
	if (!elements)
		return (print_error_get_elem("Malloc failed"), NULL);
	check_elements(cub, elements);
	if (!valid_ids(elements))
		print_error("Duplicate or missing element", NULL);
	return (cub);
}
