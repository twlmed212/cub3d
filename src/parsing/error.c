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

#include "../../includes/cub3d.h"

void	print_error(const char *message, const char *id)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)message, 2);
	if (id)
		ft_putstr_fd((char *)id, 2);
	ft_putstr_fd("\n", 2);
	free_grabage();
	exit(1);
}

void	print_error_get_elem(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}

void	print_error_rgb(const char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)message, 2);
	ft_putstr_fd("\n", 2);
	free_grabage();
	exit(1);
}

void	error_space(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}

void	print_error_map(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	free_grabage();
	exit(1);
}
