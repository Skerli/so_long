t_vars where_moove(t_vars, int keycode)
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
	
}