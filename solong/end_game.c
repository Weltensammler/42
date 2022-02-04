/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:29:38 by bschende          #+#    #+#             */
/*   Updated: 2022/02/04 17:41:59 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	endgame(t_solong *vars)
{
	printf("You escaped :) you needed %i moves for this!", vars->player_moves);
	freedom(vars);
	exit(0);
}

void	wrong_format(t_solong *vars)
{
	printf("Wrong Map format! (.ber)");
	free(vars->path);
	exit(0);
}

int	goodbye(t_solong *vars)
{
	freedom(vars);
	exit(0);
}

void	freedom(t_solong *vars)
{
	freemap(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->pl);
	free(vars->it);
	free(vars->fl);
	free(vars->ex);
}

void	freemap(t_solong *vars)
{
	int	i;

	i = 0;
	free(vars->line);
	free(vars->path);
	free(vars->string);
	free(vars->array);
	while (vars->array[i])
	{
		free(vars->array[i]);
		i++;
	}
}
