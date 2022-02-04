/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:29:38 by bschende          #+#    #+#             */
/*   Updated: 2022/02/04 01:15:25 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	endgame(t_solong *vars)
{
	printf("You escaped :) you needed %i moves for this!", vars->player_moves);
	//freedom(vars);
	exit(0);
}

void	wrong_format(void)
{
	printf("Wrong Map format! (.ber)");
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
	if (vars->line)
		free(vars->line);
	if (vars->string)
		free(vars->string);
	if (vars->array)
		free(vars->array);
}
