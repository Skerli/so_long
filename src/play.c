#include "so_long.c"

t_vars may_moove(t_vars v, int x, int y)
{
	v.may = 1;
	if (v.map[v.p_i + y][v.p_j + x] == '1')
		v.may = 0;
	if (v.map[v.p_i + y][v.p_j + x] == 'C')
	{
		v.map[v.p_i][v.p_j] = '0')
		v.map[v.p_i + y][v.p_j + x] = 'P')
		v.c_size--;	
	}
	if (v.may == 1)
	{
		v.p_i + y;
		v.p_j + x;
	}
	return (v);
}

t_vars where_moove(t_vars v, int keycode)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (keycode == 13) //W
		y--
	if (keycode == 0) //A
		x--;
	if (keycode == 1) //S
		y++;
	if (keycode == 2) //D
		x++;
	v = may_moove(v, x, y);
	if (v.may == 1)
	{
		v.p_i += y;
		v.p_j += x;
	}
	return (v);
}
