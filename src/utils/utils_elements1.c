/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_elements1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 06:29:49 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/23 07:30:01 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	***sort_elements(char ***elements)
{
	int		i;
	char	**str;

	if (!elements)
		return (NULL);
	i = -1;
	while (elements[++i])
	{
		if (elements[i + 1] && ft_strcmp(elements[i][0], elements[i
				+ 1][0]) < 0)
		{
			str = elements[i + 1];
			elements[i + 1] = elements[i];
			elements[i] = str;
			i = -1;
		}
	}
	return (elements);
}

char	***split_elements(char **cub_elem)
{
	char	***elements;
	int		i;

	elements = ft_malloc(sizeof(char **) * (count_element(cub_elem) + 1));
	if (!elements)
		return (NULL);
	i = 0;
	while (cub_elem[i])
	{
		elements[i] = ft_split(cub_elem[i], ' ');
		if (!elements[i])
		{
			printf("Error\nFailed to split element line\n");
			free_grabage();
			exit(1);
		}
		i++;
	}
	elements[i] = NULL;
	return (sort_elements(elements));
}

void	print_texture(const char *message, const char *id)
{
	printf("Error\n");
	if (id)
		printf(message, id);
	else
		printf("%s", message);
	printf("\n");
	free_grabage();
	exit(1);
}

void	check_texture(char **element, char *id)
{
	int	fd;

	if (!element || !element[0] || !element[1])
		print_texture("Missing texture path for ", id);
	clean_path(element[1]);
	if (ft_strcmp(element[0], id) != 0)
		print_texture("Invalid texture identifier", NULL);
	if (element[2])
		print_texture("Too many arguments for ", id);
	if (!check_xpm(element[1]))
		print_texture("Texture must be name + .xpm : %s", element[1]);
	fd = open(element[1], O_RDONLY);
	if (fd < 0)
		print_texture("Cannot open texture file: %s", element[1]);
	close(fd);
}

unsigned char	*check_rgb_values(char **rgb)
{
	int				i;
	int				n;
	unsigned char	*str;

	str = ft_malloc(3);
	if (!str)
		print_error_rgb("Malloc failed");
	i = 0;
	while (rgb[i])
	{
		if (!ft_isdigit_str(rgb[i]))
			print_error_rgb("RGB must contain only numbers");
		n = ft_atoi(rgb[i]);
		if (n < 0 || n > 255)
			print_error_rgb("RGB value must be between 0 and 255");
		str[i] = n;
		i++;
	}
	if (i != 3)
		print_error_rgb("RGB must contain exactly 3 values");
	return (str);
}
