/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 06:29:08 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/23 06:29:09 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_args(char **av, const char *ext)
{
	int	len;

	len = strlen(av[1]);
	if (len < 5 || *(av[1] + len - 5) == '/')
	{
		printf("Error\nInvalid path\n");
		exit(1);
	}
	if (ft_strncmp(av[1] + len - 4, ext, 4) != 0)
	{
		printf("Error\nInvalid map extension\n");
		exit(1);
	}
}
