/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:06:15 by elikavak          #+#    #+#             */
/*   Updated: 2024/10/18 16:59:20 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_memory(char **s1, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (s1[i])
			free(s1[i]);
		i++;
	}
	free(s1);
}

static int	word_count(char *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*get_word(char	**s, char c)
{
	size_t	len;

	while (**s && **s == c)
		*s = *s + 1;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	if (len == 0)
		return (0);
	*s += len;
	return (ft_substr((const char *) *s - len, 0, len));
}

char	**ft_split(char const *s, char c)
{
	char	**s1;
	char	*str;
	int		s1_len;
	int		i;

	str = (char *) s;
	s1_len = word_count((char *) s, c) + 1;
	s1 = (char **) malloc(sizeof(char *) * s1_len);
	if (!s1)
		return (0);
	i = 0;
	while (i < s1_len)
	{
		s1[i] = get_word(&str, c);
		if (!s1[i] && i != s1_len - 1)
		{
			free_memory(s1, i);
			return (0);
		}
		i++;
	}
	return (s1);
}
