/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:59:47 by abmoudni          #+#    #+#             */
/*   Updated: 2024/11/12 17:59:51 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb <= 9 && nb >= 0)
	{
		ft_putchar_fd(nb + '0', fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}

// int main(){
//     int number = 234;  // Number to test
//     int fd = 1;           // File descriptor 1 for stdout

//     // Call ft_putnbr_fd to print the number to stdout
//     ft_putnbr_fd(number, fd);
//     write(fd, "\n", 1);   // Print a new line after the number

//     return (0);
// }
