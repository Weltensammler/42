/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:44:34 by ben               #+#    #+#             */
/*   Updated: 2022/04/11 17:27:20 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapab(t_pushswap *vars)
{
	int	temp;

	if (vars->sizea > 1 && vars->sizeb > 1)
	{
		temp = vars->sta[0];
		vars->sta[0] = vars->sta[1];
		vars->sta[1] = temp;
		temp = vars->stb[0];
		vars->stb[0] = vars->stb[1];
		vars->stb[1] = temp;
		write(1, "ss\n", 3);
	}
}

void	rotateab(t_pushswap *vars)
{
	int	temp;
	int	i;

	i = 0;
	temp = vars->sta[0];
	while (i < (vars->sizea - 1))
	{
		vars->sta[i] = vars->sta[i + 1];
		i++;
	}
	vars->sta[vars->sizea - 1] = temp;
	i = 0;
	temp = vars->stb[0];
	while (i < (vars->sizeb - 1))
	{
		vars->stb[i] = vars->stb[i + 1];
		i++;
	}
	vars->stb[vars->sizeb - 1] = temp;
	write(1, "rr\n", 3);
}

void	rrotateab(t_pushswap *vars)
{
	int	temp;
	int	i;

	i = (vars->sizea - 1);
	temp = vars->sta[i];
	while (i > 0)
	{
		vars->sta[i] = vars->sta[i - 1];
		i--;
	}
	vars->sta[0] = temp;
	i = (vars->sizeb - 1);
	temp = vars->stb[i];
	while (i > 0)
	{
		vars->stb[i] = vars->stb[i - 1];
		i--;
	}
	vars->stb[0] = temp;
	write(1, "rrr\n", 4);
}
