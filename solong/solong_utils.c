/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:37:01 by bschende          #+#    #+#             */
/*   Updated: 2022/02/02 21:28:39 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map(t_solong *vars)
{
	vars->string = malloc(sizeof(char));
	while ((vars->line = get_next_line(vars->fd)))
		vars->string = ft_strjoin(vars->string, vars->line);
	vars->lines = countlines(vars->string);
	vars->col = countcol(vars->string);
	vars->x = vars->col * 100;
	vars->y = vars->lines * 100;
	if (!validchar(vars->string))
		return (0);
	vars->array = ft_split(vars->string, '\n');
	if (!rectangle(vars->array))
		return (0);
	if (!walledin(vars->array, vars->lines, vars->col))
	{
		printf("ERROR map not walled in!");
		return (0);
	}
	return (0);
}

int	*find_playerx(char **array)
{
	int	x;
	int	y;
	int	position[2];

	x = 0;
	y = 0;
	while (array[y][x])
	{
		while (array[y][x])
		{
			if (array[y][x] == 'P')
			{
				position[0] = y;
				position[1] = x;
				return (position);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	load_images(t_solong *vars)
{
	load_img_wall(&*vars);
	load_img_player(&*vars);
	load_img_item(&*vars);
	load_img_floor(&*vars);
	load_img_exit(&*vars);
}

void	draw_map(t_solong *vars)
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
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wa, j * 100, i * 100);
			if (vars->array[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->fl, j * 100, i * 100);
			if (vars->array[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->pl, j * 100, i * 100);
			if (vars->array[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->it, j * 100, i * 100);
			if (vars->array[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->ex, j * 100, i * 100);
			j++;
		}
		j = 0;
		i++;
	}
}
