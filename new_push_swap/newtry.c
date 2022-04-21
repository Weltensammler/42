/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtry.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:22:11 by ben               #+#    #+#             */
/*   Updated: 2022/04/21 15:21:26 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorythm(int size, t_pushswap *vars)
{
	int	i;
	int	array[50];

	i = 0;
	vars->value = 0;
	if (size > 1)
	{
		while (size > 3)
		{
			array[i] = chunkingplusa(size, vars);
			size = size - array[i++];
		}
		i--;
		size = uptothree(size, vars);
		while (i > -1)
		{
			while (array[i] > 0)
			{
				vars->value = chunkingplusb(array[i], vars);
				array[i] = array[i] - vars->value;
				algorythm(vars->value, vars);
			}
			i--;
		}
	}
}

int	chunkingplusa(int size, t_pushswap *vars)
{
	vars->i = 0;
	vars->j = 0;
	vars->mid = findmid(vars->sta, size);
	vars->topush = counttopusha(vars->sta, vars->mid, size);
	while (vars->i < vars->topush)
	{
		if (vars->sta[0] <= vars->mid)
		{
			pushb(vars);
			vars->i++;
		}
		else
		{
			rotatea(vars);
			vars->j++;
		}
	}
	while (vars->j > 0)
	{
		rrotatea(vars);
		vars->j--;
	}
	return (vars->topush);
}

int	chunkingplusb(int size, t_pushswap *vars)
{
	vars->i = 0;
	vars->j = 0;
	vars->mid = findmid(vars->stb, size);
	vars->topush = counttopushb(vars->stb, vars->mid, size);
	while (vars->i < vars->topush)
	{
		if (vars->stb[0] >= vars->mid)
		{
			pusha(vars);
			vars->i++;
		}
		else
		{
			rotateb(vars);
			vars->j++;
		}
	}
	while (vars->j > 0)
	{
		rrotateb(vars);
		vars->j--;
	}
	return (vars->topush);
}

int	uptothree(int size, t_pushswap *vars)
{
	if (size == 3)
	{
		sortthreeplusa(vars);
		size = 0;
	}
	if (size == 2)
	{
		if (vars->sta[0] > vars->sta[1])
			swapa(vars);
		size = 0;
	}
	if (size == 1)
		size = 0;
	return (size);
}
