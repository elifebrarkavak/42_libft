/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:32:28 by elikavak          #+#    #+#             */
/*   Updated: 2024/10/15 17:45:54 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *s1, const char *s2, size_t s1_len)
{
	size_t	i;
	size_t	s2_len;

	i = 0;
	s2_len = ft_strlen(s2);
	if (s1_len != 0)
	{
		while (s2[i] && (i < s1_len - 1))
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
	}
	return (s2_len);
}
