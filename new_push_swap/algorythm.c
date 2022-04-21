/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:06:23 by bschende          #+#    #+#             */
/*   Updated: 2022/04/21 13:00:50 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunkinga(t_pushswap *vars)
{
	int	mid;
	int	topush;
	int	i;

	i = 0;
	mid = findmid(vars->sta, vars->sizea);
	topush = counttopusha(vars->sta, mid, vars->sizea);
	while (i < topush)
	{
		if (vars->sta[0] <= mid)
		{
			pushb(vars);
			i++;
		}
		else if (vars->sta[vars->sizea - 1] <= mid)
		{
			rrotatea(vars);
			pushb(vars);
			i++;
		}
		else
			rotatea(vars);
	}
	return (topush);
}

int	checkifsorteda(t_pushswap *vars)
{
	int	i;

	i = 0;
	while (i + 1 < vars->sizea)
	{
		if (vars->sta[i] < vars->sta[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	checkifsortedb(t_pushswap *vars)
{
	int	i;

	i = 0;
	while (i + 1 < vars->sizeb)
	{
		if (vars->stb[i] > vars->stb[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	sortthreea(t_pushswap *vars)
{
	if (!checkifsorteda(vars))
	{
		if (vars->sta[0] - vars->sta[1] == -2)
		{
			rrotatea(vars);
			swapa(vars);
		}
		if (vars->sta[0] - vars->sta[1] == -1 && vars->sta[1] > vars->sta[2])
			rrotatea(vars);
		if (vars->sta[0] - vars->sta[1] == 1 && vars->sta[1] < vars->sta[2])
			swapa(vars);
		if (vars->sta[0] - vars->sta[1] == 2)
			rotatea(vars);
		if (vars->sta[0] - vars->sta[1] == 1 && vars->sta[1] > vars->sta[2])
		{
			swapa(vars);
			rrotatea(vars);
		}
	}
}

void	sortfive(t_pushswap *vars)
{
	while (vars->sizea > 3)
	{
		if (vars->sta[0] < 3)
			pushb(vars);
		if (vars->sta[vars->sizea - 1] < 3)
		{
			rrotatea(vars);
			pushb(vars);
		}
		else
			rotatea(vars);
	}
	sortthreea(vars);
	if (vars->stb[0] > vars->stb[1])
	{
		pusha(vars);
		pusha(vars);
	}
	if (vars->stb[0] < vars->stb[1])
	{
		rotateb(vars);
		pusha(vars);
		pusha(vars);
	}
}
