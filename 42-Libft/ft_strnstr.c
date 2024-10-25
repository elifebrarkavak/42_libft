/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:47:44 by elikavak          #+#    #+#             */
/*   Updated: 2024/10/15 17:40:06 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*str2;

	if (*s2 == '\0')
		return ((char *)(s1));
	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (str1[i] && i < len)
	{
		j = 0;
		while (str2[j] && (i + j < len) && (str1[i + j] == str2[j]))
		{
			j++;
		}
		if (str2[j] == '\0')
			return (&str1[i]);
		i++;
	}
	return (0);
}
