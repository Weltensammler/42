/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:26:29 by bschende          #+#    #+#             */
/*   Updated: 2022/02/03 21:45:57 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_solong *vars)
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
			printf("%i\n", vars->player_moves);
			draw_map(vars);
		}
	}
}

void	move_up(t_solong *vars)
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
			printf("%i\n", vars->player_moves);
			draw_map(vars);
		}
	}
}

void	move_down(t_solong *vars)
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
			printf("%i\n", vars->player_moves);
			draw_map(vars);
		}
	}
}

void	move_left(t_solong *vars)
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
			printf("%i\n", vars->player_moves);
			draw_map(vars);
		}
	}
}
