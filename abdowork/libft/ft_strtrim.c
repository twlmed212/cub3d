/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:53:51 by abmoudni          #+#    #+#             */
/*   Updated: 2024/11/12 19:03:37 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		star;
	int		end;
	char	*new;
	int		len;

	star = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	while (s1[star] && ft_strchr(set, s1[star]))
		star++;
	end = ft_strlen(s1) - 1;
	while (end >= star && ft_strchr(set, s1[end]))
		end--;
	if (end < star)
		return (ft_strdup(""));
	len = end - star + 1;
	new = ft_substr(s1, star, len);
	return (new);
}
// #include <stdio.h>
// int main()
// {
// 	char *s = "ab abdesamad ab";
// 	char *c = "ab";

// 	printf("%s", ft_strtrim(s, c));
// }
