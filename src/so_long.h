/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:13:22 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/10 19:59:31 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*typedef struct s_img {

	void	wall;
	void	player;
	void	emty;

}				t_img;*/

typedef struct s_vars {
	//t_img	img;
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
	int		i;
	int		j;
	int		x;
	int		y;
	char	**map;

}				t_vars;

t_vars	search(t_vars v, char c);
void	juu(char **arr);

#endif
