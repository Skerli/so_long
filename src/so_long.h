/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:13:22 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/15 18:42:12 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*wall;
	void	*player;
	void	*door;
	void	*eat;
	void	*emty;
	int		map_i;
	int		map_j;
	int		p_i;
	int		p_j;
	int		e_i;
	int		e_j;
	int		i;
	int		j;
	int		x;
	int		y;
	int		may;
	int		c_size;
	int		p_size;
	int		e_size;
	int		space;
	int		count;
	char	**map;
	char	*mes;

}				t_vars;

t_vars	search(t_vars v, char c);
void	juu(char **arr);
void	juu_exit(t_vars vars);
void	ft_putnbr(int num);
int		sclose(t_vars *vars);
//
t_vars	may_moove(t_vars v, int x, int y);
t_vars	where_moove(t_vars v, int keycode);
int		bind(int keycode, t_vars *vars);

//
t_vars	read_map(char *map, t_vars vars);
t_vars	len_map_checker(char *map, t_vars vars, int q);
int		name_checker(char	*name);

//
char	*ft_itoa(int n);

#endif
