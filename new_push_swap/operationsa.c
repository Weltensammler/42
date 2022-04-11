/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:03:18 by ben               #+#    #+#             */
/*   Updated: 2022/04/11 15:38:44 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapa(t_pushswap *vars)
{
	int	temp;

	if (vars->sizea > 1)
	{
		temp = vars->sta[0];
		vars->sta[0] = vars->sta[1];
		vars->sta[1] = temp;
		write(1, "sa\n", 3);
	}
}

void	pusha(t_pushswap *vars)
{
	int	temp;
	int	i;

	i = 0;
	//ft_printf("\n		%i	%i\n",vars->sizea, vars->sizeb);
	temp = vars->stb[0];
	if (vars->sizeb > 0)
	{
		while (i < (vars->sizeb - 1))
		{
			vars->stb[i] = vars->stb[i + 1];
			i++;
		}
		vars->stb[vars->sizeb - 1] = 0;
		i = (vars->sizeb + vars->sizea);
		while (i >= 2)
		{
			vars->sta[i - 1] = vars->sta[i - 2];
			i--;
		}
		vars->sta[0] = temp;
		write(1, "pa\n", 3);
		vars->sizeb = vars->sizeb - 1;
		vars->sizea = vars->sizea + 1;
	}
}

void	rotatea(t_pushswap *vars)
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
	write(1, "ra\n", 3);
}

void	rrotatea(t_pushswap *vars)
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
	write(1, "rra\n", 4);
}
