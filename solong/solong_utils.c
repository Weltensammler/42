/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:37:01 by bschende          #+#    #+#             */
/*   Updated: 2022/02/16 14:18:16 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_solong *vars)
{
	vars->string = malloc(sizeof(char));
	while (vars->line)
	{
		vars->line = get_next_line(vars->fd);
		if (vars->line)
			vars->string = ft_strjoin(vars->string, vars->line);
	}
	vars->lines = countlines(vars);
	vars->col = countcol(vars);
	vars->x = vars->col * 100;
	vars->y = vars->lines * 100;
	validchar(vars);
	check_min_objects(vars);
	vars->array = ft_split(vars->string, '\n');
	rectangle(vars);
	if (!walledin(vars))
	{
		printf("ERROR map not walled in!");
		freemap(vars);
		exit(0);
	}
}

void	find_player(t_solong *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vars->ccount = 0;
	while (vars->array[y])
	{
		while (vars->array[y][x])
		{
			if (vars->array[y][x] == 'P')
			{
				vars->pl_y = y;
				vars->pl_x = x;
			}
			if (vars->array[y][x] == 'C')
				vars->ccount++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	load_images(t_solong *vars)
{
	load_img_wall(vars);
	load_img_player(vars);
	load_img_item(vars);
	load_img_floor(vars);
	load_img_exit(vars);
}

void	imgtowin(t_solong *vars, void *img, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, j * 100, i * 100);
}

int	draw_map(t_solong *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (vars->array[i])
	{
		while (vars->array[i][j])
		{
			if (vars->array[i][j] == '1')
				imgtowin(vars, vars->wa, i, j);
			if (vars->array[i][j] == '0')
				imgtowin(vars, vars->fl, i, j);
			if (vars->array[i][j] == 'P')
				imgtowin(vars, vars->pl, i, j);
			if (vars->array[i][j] == 'C')
				imgtowin(vars, vars->it, i, j);
			if (vars->array[i][j] == 'E')
				imgtowin(vars, vars->ex, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
