/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:41:36 by elikavak          #+#    #+#             */
/*   Updated: 2024/10/15 11:38:39 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	num_of_el(int n)
{
	size_t	cont;

	cont = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			cont = 11;
			return (cont);
		}
		n *= -1;
		cont++;
	}
	while (n > 9)
	{
		n = n / 10;
		cont++;
	}
	cont++;
	return (cont);
}

static	void	add_el(int n, int len, char *res)
{
	int	j;

	if (n < 0)
	{
		res[0] = '-';
		if (n == -2147483648)
		{
			res[1] = '2';
			n = -147483648;
		}
		n *= -1;
	}
	j = len - 1;
	while (n > 0)
	{
		res[j] = ((n % 10) + '0');
		n = n / 10;
		j--;
	}
	res[len] = '\0';
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	len = num_of_el(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	add_el(n, len, res);
	return (res);
}
