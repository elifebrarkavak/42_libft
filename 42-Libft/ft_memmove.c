/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:27:56 by elikavak          #+#    #+#             */
/*   Updated: 2024/10/21 08:08:55 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (s1 == s2)
		return (s1);
	else if (str1 < str2)
		ft_memcpy(s1, s2, n);
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			str1[i] = str2[i];
		}
	}
	return (s1);
}
