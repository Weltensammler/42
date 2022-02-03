/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:34:43 by bschende          #+#    #+#             */
/*   Updated: 2022/02/03 17:09:04 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closewin(int keycode, t_solong *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 100)
	{
		if (vars->array[vars->pl_y][vars->pl_x + 1] != '1')
		{
			if (vars->array[vars->pl_y][vars->pl_x + 1] == 'C')
				vars->ccount = vars->ccount - 1;
			if (vars->array[vars->pl_y][vars->pl_x + 1] == 'E' && vars->ccount == 0)
			{
				vars->player_moves++;
				endgame(vars);
			}
			if (vars->array[vars->pl_y][vars->pl_x + 1] != 'E')
			{
				vars->player_moves++;
				vars->array[vars->pl_y][vars->pl_x] = '0';
				vars->pl_x = vars->pl_x + 1;
				vars->array[vars->pl_y][vars->pl_x] = 'P';
				draw_map(vars);
			}
		}
	}
	if (keycode == 119)
	{
		if (vars->array[vars->pl_y - 1][vars->pl_x] != '1')
		{
			if (vars->array[vars->pl_y - 1][vars->pl_x] == 'C')
				vars->ccount = vars->ccount - 1;
			if (vars->array[vars->pl_y - 1][vars->pl_x] == 'E' && vars->ccount == 0)
			{
				vars->player_moves++;
				endgame(vars);
			}
			if (vars->array[vars->pl_y - 1][vars->pl_x] != 'E')
			{
				vars->player_moves++;
				vars->array[vars->pl_y][vars->pl_x] = '0';
				vars->pl_y = vars->pl_y - 1;
				vars->array[vars->pl_y][vars->pl_x] = 'P';
				draw_map(vars);
			}
		}
	}
	if (keycode == 115)
	{
		if (vars->array[vars->pl_y + 1][vars->pl_x] != '1')
		{
			if (vars->array[vars->pl_y + 1][vars->pl_x] == 'C')
				vars->ccount = vars->ccount - 1;
			if (vars->array[vars->pl_y + 1][vars->pl_x] == 'E' && vars->ccount == 0)
			{
				vars->player_moves++;
				endgame(vars);
			}
			if (vars->array[vars->pl_y + 1][vars->pl_x] != 'E')
			{
				vars->player_moves++;
				vars->array[vars->pl_y][vars->pl_x] = '0';
				vars->pl_y = vars->pl_y + 1;
				vars->array[vars->pl_y][vars->pl_x] = 'P';
				draw_map(vars);
			}
		}
	}
	if (keycode == 97)
	{
		if (vars->array[vars->pl_y][vars->pl_x -1] != '1')
		{
			if (vars->array[vars->pl_y][vars->pl_x - 1] == 'C')
				vars->ccount = vars->ccount - 1;
			if (vars->array[vars->pl_y][vars->pl_x - 1] == 'E' && vars->ccount == 0)
			{
				vars->player_moves++;
				endgame(vars);
			}
			if (vars->array[vars->pl_y][vars->pl_x - 1] != 'E')
			{
				vars->player_moves++;
				vars->array[vars->pl_y][vars->pl_x] = '0';
				vars->pl_x = vars->pl_x - 1;
				vars->array[vars->pl_y][vars->pl_x] = 'P';
				draw_map(vars);
			}
		}
	}
	printf("%i\n", vars->player_moves);
	return (0);
}

int	main(int argc, char **argv)
{
	t_solong	vars;

	vars.player_moves = 0;
	vars.fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	get_map(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "so_long");
	find_player(&vars);
	load_images(&vars);
	draw_map(&vars);
	mlx_key_hook(vars.win, closewin, &vars);
	mlx_loop(vars.mlx);
	free(&vars);
	return (0);
}
