/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:34:16 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/12 16:29:09 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	search(t_vars v, char c)
{
	int	i;
	int	j;

	i = 0;
	while (v.map[i])
	{
		j = 0;
		while (v.map[i][j])
		{
			if (v.map[i][j] == c)
			{
				v.y = i;
				v.x = j;
				return (v);
			}
			j++;
		}
		i++;
	}
	return (v);
}

void	juu(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
