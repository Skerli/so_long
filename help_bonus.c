/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:34:16 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/26 15:21:31 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	juu_exit(t_vars vars, int key)
{
	if (key == 1 || key == 2)
	{
		juu(vars.map);
		mlx_destroy_window(vars.mlx, vars.win);
	}
	if (key == 2 || key == 1)
	{
		mlx_destroy_image(vars.mlx, vars.wall);
		mlx_destroy_image(vars.mlx, vars.player);
		mlx_destroy_image(vars.mlx, vars.emty);
		mlx_destroy_image(vars.mlx, vars.eat);
		mlx_destroy_image(vars.mlx, vars.door);
		mlx_destroy_image(vars.mlx, vars.door_open);
		mlx_destroy_image(vars.mlx, vars.enemy);
		mlx_destroy_image(vars.mlx, vars.enemy_anime);
		mlx_destroy_image(vars.mlx, vars.player_anime);
		exit(0);
	}
}

void	ft_putnbr(int num)
{
	if (num >= 10)
		ft_putnbr(num / 10);
	num = (num % 10) + 48;
	write(1, &num, 1);
}

int	sclose(t_vars *vars)
{
	juu_exit(*vars, 2);
	return (0);
}
