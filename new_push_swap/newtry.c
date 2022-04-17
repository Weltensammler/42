/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtry.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:22:11 by ben               #+#    #+#             */
/*   Updated: 2022/04/18 01:00:19 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algorythm(int size, t_pushswap *vars)
{
	int	i;
	int	value;
	int	blocks;
	int	*array;
	int	h;

	i = -1;
	h = 0;
	value = 0;
	blocks = chunks(vars);
	if (size > 3)
	{
		array = createarray(blocks);
		i++;
	}
	if (size > 1)
	{
		while (size > 3)
		{
			array[i] = chunkingplusa(size, vars);
			size = size - array[i];
			i++;
			h = 0;
			while (h < vars->size)
			{
				printf("%i	%i	%i	%i\n", vars->sta[h], vars->stb[h], vars->sizea, vars->sizeb);
				h++;
			}
		}
		i--;
		printf("\nafter while1 i = %i\n", i);
		if (size == 3)
		{
			sortthreeplusa(vars);
			size = 0;
			printf("\nOK\n");
		}
		if (size == 2)
		{
			if (vars->sta[0] > vars->sta[1])
				swapa(vars);
			size = 0;
		}
		if (size == 1)
			size = 0;
		h = 0;
		while (h < vars->size)
		{
			printf("%i	%i	%i	%i	i = %i\n", vars->sta[h], vars->stb[h], vars->sizea, vars->sizeb, i);
			h++;
		}
		/*check while condition, because array[i] needs to be 0 before moving on to the next chunk*/
		while (i > -1)
		{
			while (array[i] > 0)
			{
				value = chunkingplusb(array[i], vars);
				array[i] = array[i] - value;
				// i--;
				algorythm(value, vars);
				printf("\nalgorythm while2\nvalue %i	size %i array[0] = %i\n", value, size, array[0]);
			}
			i--;
		}
		value = size;
	}
	free(array);
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
	printf("\nto push %i mid %i\n", topush, mid);
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
	printf("\nto push %i mid %i\n", topush, mid);
	while (i < topush)
	{
		//ft_printf("\n%i\n", topush);
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
