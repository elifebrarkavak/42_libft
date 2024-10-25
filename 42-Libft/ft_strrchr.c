/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:56:18 by elikavak          #+#    #+#             */
/*   Updated: 2024/10/15 17:18:44 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	char	*s;
	int		i;

	i = ft_strlen(str);
	s = (char *)str;
	if ((char)n == '\0')
		return (&s[i]);
	i -= 1;
	while (i >= 0)
	{
		if (s[i] == (char)n)
			return (&s[i]);
		i--;
	}
	return (0);
}
