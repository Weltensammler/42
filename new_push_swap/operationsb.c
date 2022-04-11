/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:10:43 by ben               #+#    #+#             */
/*   Updated: 2022/04/11 15:37:44 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapb(t_pushswap *vars)
{
	int	temp;

	if (vars->sizeb > 1)
	{
		temp = vars->stb[0];
		vars->stb[0] = vars->stb[1];
		vars->stb[1] = temp;
		write(1, "sb\n", 3);
	}
}

void	pushb(t_pushswap *vars)
{
	int	temp;
	int	i;

	i = 0;
	//ft_printf("\n		%i	%i\n",vars->sizea, vars->sizeb);
	temp = vars->sta[0];
	if (vars->sizea > 0)
	{
		while (i < (vars->sizea - 1))
		{
			vars->sta[i] = vars->sta[i + 1];
			i++;
		}
		vars->sta[vars->sizea - 1] = 0;
		i = (vars->sizeb + vars->sizea);
		while (i >= 2)
		{
			vars->stb[i - 1] = vars->stb[i - 2];
			i--;
		}
		vars->stb[0] = temp;
		write(1, "pb\n", 3);
		vars->sizeb = vars->sizeb + 1;
		vars->sizea = vars->sizea - 1;
	}
}

void	rotateb(t_pushswap *vars)
{
	int	temp;
	int	i;

	i = 0;
	temp = vars->stb[0];
	while (i < (vars->sizeb - 1))
	{
		vars->stb[i] = vars->stb[i + 1];
		i++;
	}
	vars->stb[vars->sizeb - 1] = temp;
	write(1, "rb\n", 3);
}

void	rrotateb(t_pushswap *vars)
{
	int	temp;
	int	i;

	i = (vars->sizeb - 1);
	temp = vars->stb[i];
	while (i > 0)
	{
		vars->stb[i] = vars->stb[i - 1];
		i--;
	}
	vars->stb[0] = temp;
	write(1, "rrb\n", 4);
}
