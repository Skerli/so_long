/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:57:06 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/12 15:32:28 by cskipjac         ###   ########.fr       */
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
		v.c_size--;
	}
	if (v.may == 1 && v.map[v.p_i][v.p_j] != 'E')
	{
		v.map[v.p_i][v.p_j] = '0';
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
