/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:57:06 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/15 17:34:52 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	may_moove(t_vars v, int x, int y)
{
	v.may = 1;
	if (v.map[v.p_i + y][v.p_j + x] == '1')
		v.may = 0;
	if (v.map[v.p_i + y][v.p_j + x] == 'C')
	{
		v.map[v.p_i][v.p_j] = '0';
		v.map[v.p_i + y][v.p_j + x] = 'P';
		v.c_size--;
	}
	if (v.may == 1 && v.map[v.p_i][v.p_j] == 'E')
	{
		v.map[v.p_i + y][v.p_j + x] = 'P';
	}
	return (v);
}

t_vars	where_moove(t_vars v, int keycode)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (keycode == 13)
		y--;
	if (keycode == 0)
		x--;
	if (keycode == 1)
		y++;
	if (keycode == 2)
		x++;
	v = may_moove(v, x, y);
	if (v.may == 1)
	{
		mlx_put_image_to_window(v.mlx, v.win, v.emty,
			((v.p_j * 64) + 64), ((v.p_i * 64) + 64));
		if (v.map[v.p_i][v.p_j] == 'E')
			mlx_put_image_to_window(v.mlx, v.win, v.door,
				((v.p_j * 64) + 64), ((v.p_i * 64) + 64));
		v.p_i += y;
		v.p_j += x;
	}
	return (v);
}

int	bind(int keycode, t_vars *vars)
{
	if (keycode == 53 || keycode == 17)
		juu_exit(*vars);
	*vars = where_moove(*vars, keycode);
	if (vars->may == 1)
	{
		vars->mes = ft_itoa(++vars->count);
		write(1, "\n", 1);
		ft_putnbr(vars->count);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->emty,
			(vars->map_j * 64) + 64, 32);
		mlx_string_put(vars->mlx, vars->win, (vars->map_j * 64) + 64, 32,
			0x0012FF3A, vars->mes);
		free(vars->mes);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
			((vars->p_j * 64) + 64), ((vars->p_i * 64) + 64));
	}
	if (vars->map[vars->p_i][vars->p_j] == 'E' && vars->c_size == 0)
		juu_exit(*vars);
	return (0);
}
