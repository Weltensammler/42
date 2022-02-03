/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:29:38 by bschende          #+#    #+#             */
/*   Updated: 2022/02/03 21:01:57 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	endgame(t_solong *vars)
{
	printf("You escaped :) you needed %i moves for this!", vars->player_moves);
	exit(0);
}

void	imagefail(void)
{
	printf("Failed to load image!");
	exit(0);
}

void	wrong_format(void)
{
	printf("Wrong Map format! (.ber)");
	exit(0);
}

int	goodbye(char *error_message)
{
	exit(0);
}
