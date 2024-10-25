/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:21:34 by elikavak          #+#    #+#             */
/*   Updated: 2024/10/18 16:24:55 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_last(char *s1, char *set, int count)
{
	int	len;
	int	last;

	len = ft_strlen(s1) - 1;
	last = len;
	while (len > count && (ft_char_in_set(s1[len], set)))
	{
		last--;
		len--;
	}
	return (last);
}

static int	ft_count_start(char *s1, char *set)
{
	int	count;
	int	j;
	int	found;

	count = 0;
	while (s1[count])
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[count] == set[j])
			{
				count++;
				found = 1;
				break ;
			}
			j++;
		}
		if (!found)
			break ;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		count;
	int		last;
	char	*res;

	if (!set)
		return (ft_strdup(s1));
	count = ft_count_start((char *)s1, (char *)set);
	last = ft_count_last((char *)s1, (char *)set, count);
	if (count > last)
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char) * (last - count + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (count <= last)
		res[i++] = s1[count++];
	res[i] = '\0';
	return (res);
}
