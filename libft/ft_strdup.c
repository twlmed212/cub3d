/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:39:21 by abmoudni          #+#    #+#             */
/*   Updated: 2024/11/13 16:25:49 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*v;
	size_t	len;

	len = ft_strlen(s);
	v = malloc(len + 1);
	if (v == NULL)
		return (NULL);
	ft_memcpy(v, s, len);
	v[len] = '\0';
	return (v);
}
/*int main(){

char	*src = "Hello";
printf("%s",strdup(src));

}*/
