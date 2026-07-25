/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 06:29:29 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/23 07:09:42 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	open_file(char *fname)
{
	int	fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nFailed to open the file\n"), -1);
	return (fd);
}

void	check_ext(char *str, char *ext)
{
	size_t	len;

	len = ft_strlen(str);
	if (len <= 4 || *(str + len - 5) == '/')
	{
		printf("filename invalide\n");
		exit(1);
	}
	if (ft_strcmp(str + len - 4, ext))
	{
		printf("Wrong extantion name\n");
		exit(1);
	}
}

t_cub	*ft_check(char **av)
{
	t_cub	*cub;

	check_ext(av[1], ".cub");
	cub = malloc(sizeof(t_cub));
	if (!cub)
	{
		printf("Error\nFailed to allocate memory for cub structure\n");
		exit(1);
	}
	ft_bzero(cub, sizeof(t_cub));
	cub->fd = open_file(av[1]);
	if (cub->fd < 0)
	{
		free(cub);
		exit(1);
	}
	if (!ft_get_elements(cub))
	{
		close(cub->fd);
		free(cub);
		exit(1);
	}
	get_map(cub);
	return (cub);
}
