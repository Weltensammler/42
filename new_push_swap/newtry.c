/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtry.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:22:11 by ben               #+#    #+#             */
/*   Updated: 2022/04/18 13:49:46 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algorythm(int size, t_pushswap *vars)
{
	int	i;
	int	value;
	int	blocks;
	int	*array;

	i = -1;
	value = 0;
	blocks = chunks(vars);
	if (size > 3)
	{
		array = malloc(sizeof(int) * blocks);
		i++;
	}
	if (size > 1)
	{
		while (size > 3)
		{
			array[i] = chunkingplusa(size, vars);
			size = size - array[i];
			i++;
		}
		i--;
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
		while (i > -1)
		{
			while (array[i] > 0)
			{
				value = chunkingplusb(array[i], vars);
				array[i] = array[i] - value;
				algorythm(value, vars);
			}
			i--;
		}
		value = size;
	}
	return (value);
}

int	chunkingplusa(int size, t_pushswap *vars)
{
	int	mid;
	int	topush;
	int	i;
	int	j;

	
	i = 0;
	j = 0;
	mid = findmid(vars->sta, size);
	topush = counttopusha(vars->sta, mid, size);
	while (i < topush)
	{
		if (vars->sta[0] <= mid)
		{
			pushb(vars);
			i++;
		}
		else
		{
			rotatea(vars);
			j++;
		}
	}
	while (j > 0)
	{
		rrotatea(vars);
		j--;
	}
	return (topush);
}

int	*createarray(int chunks)
{
	int	*array;

	array = malloc(sizeof(int) * chunks);
	return (array);
}

int	chunkingplusb(int size, t_pushswap *vars)
{
	int	mid;
	int	topush;
	int	i;
	int	j;

	
	i = 0;
	j = 0;
	mid = findmid(vars->stb, size);
	topush = counttopushb(vars->stb, mid, size);
	while (i < topush)
	{
		if (vars->stb[0] >= mid)
		{
			pusha(vars);
			i++;
		}
		else
		{
			rotateb(vars);
			j++;
		}
	}
	while (j > 0)
	{
		rrotateb(vars);
		j--;
	}
	return (topush);
}
