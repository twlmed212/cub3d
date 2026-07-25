/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:51:02 by abmoudni          #+#    #+#             */
/*   Updated: 2024/11/15 17:01:20 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*m;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	p = (unsigned char *)dest;
	m = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		p[i] = m[i];
		i++;
	}
	return (dest);
}
/*int main()
{
		char dest[40]="abde  sama";
		char src[40]="hello ";
			ft_memcpy(dest,src,5);
			printf("%s",dest);
 } */
