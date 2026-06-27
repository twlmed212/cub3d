/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:08:42 by abmoudni          #+#    #+#             */
/*   Updated: 2024/11/11 17:44:58 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_char(char *s, unsigned int number, int len)
{
	while (number > 0)
	{
		s[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (s);
}

static int	get_num_length(int n)
{
	int	length;

	if (n == 0)
		return (1);
	length = 0;
	if (n < 0)
		length++;
	while (n != 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*str;
	long	nb;

	nb = n;
	length = get_num_length(n);
	str = (char *)malloc(length + 1);
	if (!str)
		return (NULL);
	str[length--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	else if (nb == 0)
	{
		str[0] = '0';
	}
	str = ft_char(str, nb, length);
	return (str);
}
/*
 int main()
 {
	 int number1 = -12345;
	 printf("The string is: %s\n", ft_itoa(number1)); // Output: -12345

	 int number2 = 56789;
	 printf("The string is: %s\n", ft_itoa(number2)); // Output: 56789

	 int number3 = 0;
	 printf("The string is: %s\n", ft_itoa(number3)); // Output: 0

	 return 0;
 }*/
