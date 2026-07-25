/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 06:29:49 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/23 07:30:01 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_error(const char *message, const char *id)
{
	printf("Error\n");
	if (id)
		printf(message, id);
	else
		printf("%s", message);
	printf("\n");
	exit(1);
}

void	print_error_get_elem(char *message)
{
	printf("Error\n%s\n", message);
}

void	print_error_rgb(const char *message)
{
	printf("Error\n%s\n", message);
	exit(1);
}

void	error_space(char *message)
{
	printf("Error : %s\n", message);
}
