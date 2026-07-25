/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:49:26 by abmoudni          #+#    #+#             */
/*   Updated: 2024/10/28 15:49:29 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*b;
	size_t	i;

	b = (char *)s;
	i = 0;
	while (i < n)
	{
		b[i] = '\0';
		i++;
	}
}
/*
int	main(void){

char	f[40] = "abdeGood";

ft_bzero(f,4);


printf("%s",f);


}*/
