/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:52:40 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/27 15:55:01 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	sprites(t_vars v)
{
	int			w;
	int			h;

	w = 64;
	h = 64;
	v.wall = mlx_xpm_file_to_image(v.mlx, "sprites/wall.xpm", &w, &h);
	v.player = mlx_xpm_file_to_image(v.mlx, "sprites/player.xpm", &w, &h);
	v.enemy = mlx_xpm_file_to_image(v.mlx, "sprites/enemy.xpm", &w, &h);
	v.emty = mlx_xpm_file_to_image(v.mlx, "sprites/emty.xpm", &w, &h);
	v.eat = mlx_xpm_file_to_image(v.mlx, "sprites/eat.xpm", &w, &h);
	v.door = mlx_xpm_file_to_image(v.mlx, "sprites/door.xpm", &w, &h);
	v.enemy_anime = mlx_xpm_file_to_image(v.mlx, "sprites/enemy_anime.xpm",
			&w, &h);
	v.player_anime = mlx_xpm_file_to_image(v.mlx, "sprites/player_anime.xpm",
			&w, &h);
	v.door_open = mlx_xpm_file_to_image(v.mlx, "sprites/door_open.xpm",
			&w, &h);
	return (v);
}

void	maprender_plus(t_vars v)
{
	v.i = -1;
	v.may = 1;
	while (v.map[++v.i])
	{
		v.j = -1;
		while (v.map[v.i][++v.j])
		{
			if (v.map[v.i][v.j] == '1')
				mlx_put_image_to_window(v.mlx, v.win, v.wall,
					(64 + (v.j * 64)), (64 + (v.i * 64)));
			if (v.map[v.i][v.j] == 'E')
				mlx_put_image_to_window(v.mlx, v.win, v.door,
					(64 + (v.j * 64)), (64 + (v.i * 64)));
			if (v.map[v.i][v.j] == 'P' && v.may == 1)
			{
				v.may = 0;
				mlx_put_image_to_window(v.mlx, v.win, v.player,
					(64 + (v.j * 64)), (64 + (v.i * 64)));
			}
			if (v.map[v.i][v.j] == 'C')
				mlx_put_image_to_window(v.mlx, v.win, v.eat,
					(64 + (v.j * 64)), (64 + (v.i * 64)));
		}
	}
	mlx_string_put(v.mlx, v.win, (v.map_j * 64) + 64, 32, 0x0012FF3A, "0");
}

void	maprender(t_vars v)
{
	v.win = mlx_new_window(v.mlx, v.map_j * 128, v.map_i * 128, "MyGame");
	maprender_plus(v);
	v = search(v, 'P');
	v.p_j = v.x;
	v.p_i = v.y;
	v = find_space_enemy(v);
	v.count = 0;
	v.where = 1;
	v.where_player = 0;
	mlx_hook(v.win, 17, 1L << 0, sclose, &v);
	mlx_key_hook(v.win, bind, &v);
	mlx_loop_hook(v.mlx, enemy_to_anime, (void *)&v);
	mlx_loop(v.mlx);
}

void	map_changer(t_vars vars, int ac, char **av, int i)
{
	int		k;

	while (++i != ac)
	{
		vars.number_map = i;
		k = name_checker(av[i]);
		vars = len_map_checker(av[i], vars, -1);
		if (vars.may != 1 || k == -1)
		{
			write(2, "Error\n Ivalid map, bad fd or name map\n", 38);
			exit(1);
		}
		vars = read_map(av[i], vars);
		maprender(vars);
	}
}

int	main(int ac, char **argv)
{
	t_vars	vars;

	if (ac < 2)
		return (1);
	vars.mlx = mlx_init();
	vars = sprites(vars);
	vars.ac = ac;
	vars.av = argv;
	map_changer(vars, ac, argv, 0);
}
