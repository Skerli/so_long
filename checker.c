/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:37:47 by cskipjac          #+#    #+#             */
/*   Updated: 2022/02/27 15:39:07 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (vars.p_size != 1)
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

t_vars	read_map(char *map, t_vars vars)
{
	char	c;
	int		i;
	int		j;
	int		fd;

	vars.map = (char **)malloc(sizeof(char *) * (vars.map_i + 1));
	i = -1;
	fd = open(map, O_RDONLY);
	while (++i != vars.map_i)
	{
		j = -1;
		vars.map[i] = (char *)malloc(sizeof(char) * (vars.map_j));
		while (++j != vars.map_j)
		{
			read(fd, &c, 1);
			vars.map[i][j] = c;
		}
		vars.map[i][j] = '\0';
	}
	vars.map[i] = NULL;
	close(fd);
	return (vars);
}

int	name_checker(char	*name)
{
	int		i;
	int		j;
	char	*dot;

	i = 0;
	j = 0;
	dot = ".ber";
	while (name[i])
		i++;
	i -= 4;
	while (dot[j])
	{
		if (dot[j] != name[i])
			return (-1);
		i++;
		j++;
	}
	return (0);
}
