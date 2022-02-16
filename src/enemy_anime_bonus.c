/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_anime_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:48:42 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/16 19:05:14 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	dooor_animation(t_vars v)
{
	int	i;
	int	j;

	i = 0;
	if (v.c_size == 0)
	{
		while (v.map[++i])
		{
			j = -1;
			while (v.map[i][++j])
			{
				if (v.map[i][j] == 'E')
				{
					mlx_put_image_to_window(v.mlx, v.win, v.emty,
						(64 + (j * 64)), (64 + (i * 64)));
					mlx_put_image_to_window(v.mlx, v.win, v.door_open,
						(64 + (j * 64)), (64 + (i * 64)));
				}
			}
		}
		return (1);
	}
	return (0);
}

static void	player_animation(t_vars v)
{
	static int	counter;

	if (counter % 10000 == 0)
	{
		mlx_put_image_to_window(v.mlx, v.win, v.emty,
			(64 + (v.p_j * 64)), (64 + (v.p_i * 64)));
		if (v.map[v.p_i][v.p_j] == 'E')
			mlx_put_image_to_window(v.mlx, v.win, v.door,
				(64 + (v.p_j * 64)), (64 + (v.p_i * 64)));
		mlx_put_image_to_window(v.mlx, v.win, v.player_anime,
			(64 + (v.p_j * 64)), (64 + (v.p_i * 64)));
		counter++;
		return ;
	}
	if (counter % 5000 == 0)
	{
		mlx_put_image_to_window(v.mlx, v.win, v.emty,
			(64 + (v.p_j * 64)), (64 + (v.p_i * 64)));
		if (v.map[v.p_i][v.p_j] == 'E')
			mlx_put_image_to_window(v.mlx, v.win, v.door,
				(64 + (v.p_j * 64)), (64 + (v.p_i * 64)));
		mlx_put_image_to_window(v.mlx, v.win, v.player,
			(64 + (v.p_j * 64)), (64 + (v.p_i * 64)));
	}
	counter++;
}

static void	enemy_animation(t_vars v)
{
	static int	counter;

	if (counter % 10000 == 0 || counter % 5000 == 0)
	{
		paint_ec(v, v.enemy_i, v.enemy_j);
		if (counter % 10000 == 0)
		{
			mlx_put_image_to_window(v.mlx, v.win, v.enemy_anime,
				(64 + (v.enemy_j * 64)), (64 + (v.enemy_i * 64)));
			counter++;
			return ;
		}
		if (counter % 5000 == 0)
			mlx_put_image_to_window(v.mlx, v.win, v.enemy,
				(64 + (v.enemy_j * 64)), (64 + (v.enemy_i * 64)));
	}
	counter++;
}

static t_vars	enemy_moov(t_vars v)
{
	static int	counter;

	if (counter % 7000 == 0)
	{
		paint_ec(v, v.enemy_i, v.enemy_j);
		if (counter % 28000 == 0)
		{
			if (v.p_i >= v.enemy_i)
				v.where_player = 1;
			else
				v.where_player = -1;
		}
		if (v.map[v.enemy_i + v.where_player][v.enemy_j + v.where] != '1')
		{
			v.enemy_j += v.where;
			v.enemy_i += v.where_player;
			mlx_put_image_to_window(v.mlx, v.win, v.enemy,
				(64 + (v.enemy_j * 64)), (64 + (v.enemy_i * 64)));
			v.where_player = 0;
		}
		else
			v.where *= -1;
	}
	counter++;
	return (v);
}

int	enemy_to_anime(t_vars *v)
{
	static int	k;

	player_animation(*v);
	enemy_animation(*v);
	*v = enemy_moov(*v);
	if (k != 1)
		k = dooor_animation(*v);
	if (v->p_i == v->enemy_i && v->p_j == v->enemy_j)
		juu_exit(*v);
	return (0);
}
