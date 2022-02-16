/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:05:54 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/16 18:18:04 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	glen(int i, int n, int *tlen)
{
	long long int	a;

	if (n < 0)
		i--;
	i++;
	while (i != tlen[0])
	{
		n = n / 10;
		i++;
	}
	a = n;
	if (a < 0)
		a = a * -1;
	return ((a % 10) + 48);
}

static int	*chis(int n, int *arr)
{
	arr[0] = 0;
	arr[1] = 0;
	if (n == 0)
		arr[0]++;
	if (n < 0)
		arr[1]++;
	while (n != 0)
	{
		n = n / 10;
		arr[0]++;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*arr;
	int		tlen[2];

	chis(n, tlen);
	arr = (char *)malloc(sizeof(*arr) * (tlen[0] + tlen[1] + 1));
	if (!arr)
		return (NULL);
	i = 0;
	if (tlen[1] == 1)
		arr[0] = '-';
	if (tlen[1] == 1)
		i++;
	while (i != (tlen[0] + tlen[1]))
	{
		arr[i] = glen(i, n, tlen);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
