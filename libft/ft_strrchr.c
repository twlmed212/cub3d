/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:56:23 by abmoudni          #+#    #+#             */
/*   Updated: 2024/11/12 22:47:41 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (s[i] == (char)c)
		return ((char *)(s + i));
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void){

// char *f= "abdellah";
// //printf("or:%s\n",strchr(f,L));
// printf("fa:%s\n",strrchr(f,0));
// printf("fa:%s\n",ft_strrchr(f,0));

// }
