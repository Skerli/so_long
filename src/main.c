/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:52:40 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/12 18:33:27 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	bind(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		juu(vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	*vars = where_moove(*vars, keycode);
	if (vars->may == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
			((vars->p_j * 64) + 64), ((vars->p_i * 64) + 64));
	}
	if (vars->p_i == vars->e_i && vars->p_j == vars->e_j && vars->c_size == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

t_vars	len_map(char *map, t_vars vars)
{
	int		fd;
	int		k;
	char	c;

	vars.map_i = 0;
	vars.map_j = 0;
	k = 0;
	vars.c_size = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("open failed on input file");
		exit(0);
	}
	while (read(fd, &c, 1) != 0)
	{
		if (c == '\n')
			vars.map_i++;
		if (c == '\n')
			k = 1;
		if (k == 0)
			vars.map_j++;
		if (c == 'C')
			vars.c_size++;
	}
	close(fd);
	return (vars);
}

t_vars	read_map(char *map, t_vars vars)
{
	char	c;
	int		i;
	int		j;
	int		fd;

	vars = len_map(map, vars);
	//printf("|i = %d|\t", vars.c_size);
	//printf("|i = %d|\t", vars.map_i);
	//printf("|j = %d|\t", vars.map_i);
	vars.map = (char **)malloc(sizeof(char *) * (vars.map_i + 1));
	i = -1;
	fd = open(map, O_RDONLY);
	while (++i != vars.map_i)
	{
		j = -1;
		vars.map[i] = (char *)malloc(sizeof(char) * (vars.map_j + 1));
		while (read(fd, &c, 1) != 0 && ++j != vars.map_j)
			vars.map[i][j] = c;
		vars.map[i][j] = '\0';
		//printf("\n%s", arr[i]);
	}
	vars.map[i] = NULL;
	close(fd);
	return (vars);
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
}

t_vars	sprites(t_vars v)
{
	int			w;
	int			h;

	v.wall = mlx_xpm_file_to_image(v.mlx, "../sprites/wall.xpm", &w, &h);
	v.player = mlx_xpm_file_to_image(v.mlx, "../sprites/player.xpm", &w, &h);
	v.emty = mlx_xpm_file_to_image(v.mlx, "../sprites/emty.xpm", &w, &h);
	v.eat = mlx_xpm_file_to_image(v.mlx, "../sprites/eat.xpm", &w, &h);
	v.door = mlx_xpm_file_to_image(v.mlx, "../sprites/door.xpm", &w, &h);
	return (v);
}

void	maprender(t_vars v)
{
	v.win = mlx_new_window(v.mlx, v.map_j * 128, v.map_i * 128, "MyGame");
	maprender_plus(v);
	v = search(v, 'P');
	v.p_j = v.x;
	v.p_i = v.y;
	v = search(v, 'E');
	v.e_j = v.x;
	v.e_i = v.y;
	mlx_key_hook(v.win, bind, &v);
	mlx_loop(v.mlx);
}

void	map_changer(t_vars vars)
{
	char	*map;
	int		i;

	map = "../maps/map2.ber";
	vars = read_map(map, vars);
	maprender(vars);
	juu(vars.map);
}

t_vars	sqwr_check(t_vars vars, char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
	{
		if (i < vars.map_j - 1 && buf[i] != '1')
			vars.may--;
		if ((i > (vars.space - vars.map_j) && i != vars.space - 1)
			&& buf[i] != '1')
			vars.may--;
		if (buf[i + 1] == '\n' && buf[i] != '1')
			vars.may--;
		if (buf[i - 1] == '\n' && buf[i] != '1')
			vars.may--;
	}
	return (vars);
}

t_vars	zanul(t_vars vars, int k, char *buf)
{
	if (k == 1)
	{
		vars.map_i = 0;
		vars.map_j = 0;
		vars.may = 1;
		vars.c_size = 0;
		vars.e_size = 0;
		vars.p_size = 0;
		vars.space = 0;
	}
	if (k == 2)
	{
		while (buf[vars.space])
			vars.space++;
		if (vars.c_size < 1)
			vars.may--;
		if (vars.e_size < 1)
			vars.may--;
		if (vars.p_size < 1)
			vars.may--;
		if (vars.map_j * vars.map_i != vars.space)
			vars.may--;
		vars = sqwr_check(vars, buf);
	}
	return (vars);
}

t_vars	len_map_checker(char *map, t_vars vars, int q)
{
	int		fd;
	char	buf[40000];

	vars = zanul(vars, 1, buf);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		vars.may--;
	if (read(fd, buf, 40000) == -1)
		vars.may--;
	while (buf[++q])
	{
		if (vars.map_i == 0)
			vars.map_j++;
		if (buf[q] == '\n')
			vars.map_i++;
		if (buf[q] == 'C')
			vars.c_size++;
		if (buf[q] == 'E')
			vars.e_size++;
		if (buf[q] == 'P')
			vars.p_size++;
	}
	vars = zanul(vars, 2, buf);
	close(fd);
	return (vars);
}

int	main(void)
{
	t_vars	vars;

	vars = len_map_checker("../maps/map2.ber", vars, -1);
	printf("MAY = %d\n", vars.may);
	/*vars.mlx = mlx_init();
	vars = sprites(vars);
	map_changer(vars);*/
}
//gcc  -Lminilibx -lmlx -framework OpenGL -framework AppKit main.c help.c play.c && ./a.out
