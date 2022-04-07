/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:44:34 by ben               #+#    #+#             */
/*   Updated: 2022/04/07 20:20:19 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapab(t_pushswap *vars)
{
	int	temp;

	if (vars->sizea > 1 && vars->sizeb > 1)
	{
		temp = vars->arraya[0];
		vars->arraya[0] = vars->arraya[1];
		vars->arraya[1] = temp;
		temp = vars->arrayb[0];
		vars->arrayb[0] = vars->arrayb[1];
		vars->arrayb[1] = temp;
		write(1, "ss\n", 3);
	}
}

void	rotateab(t_pushswap *vars)
{
	int	temp;
	int	i;

	i = 0;
	temp = vars->arraya[0];
	while (i < (vars->sizea - 1))
	{
		vars->arraya[i] = vars->arraya[i + 1];
		i++;
	}
	vars->arraya[vars->sizea - 1] = temp;
	i = 0;
	temp = vars->arrayb[0];
	while (i < (vars->sizeb - 1))
	{
		vars->arrayb[i] = vars->arrayb[i + 1];
		i++;
	}
	vars->arrayb[vars->sizeb - 1] = temp;
	write(1, "rr\n", 3);
}

void	rrotateab(t_pushswap *vars)
{
	int	temp;
	int	i;

	i = (vars->sizea - 1);
	temp = vars->arraya[i];
	while (i > 0)
	{
		vars->arraya[i] = vars->arraya[i - 1];
		i--;
	}
	vars->arraya[0] = temp;
	write(1, "rra\n", 4);
	i = (vars->sizeb - 1);
	temp = vars->arrayb[i];
	while (i > 0)
	{
		vars->arrayb[i] = vars->arrayb[i - 1];
		i--;
	}
	vars->arrayb[0] = temp;
	write(1, "rrb\n", 4);
}
