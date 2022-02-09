#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
//

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_player;
	void	*img_emty;
	int		x;
	int		y;

}				t_vars;

#endif
