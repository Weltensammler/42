/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:29:38 by bschende          #+#    #+#             */
/*   Updated: 2022/02/04 00:01:45 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	endgame(t_solong *vars)
{
	printf("You escaped :) you needed %i moves for this!", vars->player_moves);
	freedom(vars);
	exit(0);
}

void	imagefail(t_solong *vars)
{
	printf("Failed to load image!");
	freedom(vars);
	exit(0);
}

void	wrong_format(t_solong *vars)
{
	printf("Wrong Map format! (.ber)");
	freedom(vars);
	exit(0);
}

int	goodbye(t_solong *vars)
{
	freedom(vars);
	exit(0);
}

void	freedom(t_solong *vars)
{
	if (vars->line)
		free(vars->line);
	if (vars->string)
		free(vars->string);
	if (vars->array)
		free(vars->array);
	mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		free(vars->mlx);
	if (vars->wa)
		free(vars->wa);
	if (vars->pl)
		free(vars->pl);
	if (vars->it)
		free(vars->it);
	if (vars->fl)
		free(vars->fl);
	if (vars->ex)
		free(vars->ex);
}
