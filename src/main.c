/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:52:40 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/09 21:10:20 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// usage:
*/

int	bind(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 13) //W
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_emty, vars->x, vars->y);
		vars->y -= 64;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player, vars->x, vars->y);
	}
	if (keycode == 0) //A
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_emty, vars->x, vars->y);
		vars->x -= 64;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player, vars->x, vars->y);
	}
	if (keycode == 1) //S
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_emty, vars->x, vars->y);
		vars->y += 64;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player, vars->x, vars->y);
	}
	if (keycode == 2) //D
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_emty, vars->x, vars->y);
		vars->x += 64;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player, vars->x, vars->y);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	char	*wall = "../sprites/door_01.xpm";
	char	*player = "../sprites/player.xpm";
	char	*emty = "../sprites/emty.xpm";
	int		img_width;
	int		img_height;
	int		x = 100;
	int		y = 100;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1800, 1500, "Hello world!");
	vars.img_wall = mlx_xpm_file_to_image(vars.mlx, wall, &img_width, &img_height);
	vars.img_player = mlx_xpm_file_to_image(vars.mlx, player, &img_width, &img_height);
	vars.img_emty = mlx_xpm_file_to_image(vars.mlx, emty, &img_width, &img_height);
	/*while (x < 900)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img_wall, x, 400);
		x += 70;
	}*/
	vars.x = 100;
	vars.y = 100;
	mlx_key_hook(vars.win, bind, &vars);
	mlx_loop(vars.mlx);
}
//gcc  -Lminilibx -lmlx -framework OpenGL -framework AppKit main.c && ./a.out
