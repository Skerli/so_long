/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:15:30 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/16 19:04:39 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	paint_ec(t_vars v, int i, int j)
{
	mlx_put_image_to_window(v.mlx, v.win, v.emty,
		(64 + (j * 64)), (64 + (i * 64)));
	if (v.map[i][j] == 'E')
		mlx_put_image_to_window(v.mlx, v.win, v.door,
			(64 + (j * 64)), (64 + (i * 64)));
	if (v.map[i][j] == 'C')
		mlx_put_image_to_window(v.mlx, v.win, v.eat,
			(64 + (j * 64)), (64 + (i * 64)));
}

t_vars	find_space_enemy(t_vars v)
{
	v.enemy_i = v.map_i - v.p_i - 1;
	while (v.map[v.enemy_i])
	{
		v.enemy_j = 1;
		while (v.map[v.enemy_i][v.enemy_j])
		{
			if (v.map[v.enemy_i][v.enemy_j] == '0')
			{
				mlx_put_image_to_window(v.mlx, v.win, v.enemy,
					(64 + (v.enemy_j * 64)), (64 + (v.enemy_i * 64)));
				return (v);
				v.enemy_j++;
			}
		}
		v.enemy_i++;
		if (v.enemy_i <= v.map_i)
			v.enemy_i = 1;
	}
	return (v);
}
