/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:34:16 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/12 15:40:06 by cskipjac         ###   ########.fr       */
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
				v.p_i = i;
				v.p_j = j;
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
