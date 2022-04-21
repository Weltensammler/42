/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:02:57 by ben               #+#    #+#             */
/*   Updated: 2022/04/21 12:13:50 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findmid(int stack[], int size)
{
	int	i;
	int	sum;
	int	mid;

	i = 0;
	sum = 0;
	mid = 0;
	while (i < size)
	{
		sum = stack[i] + sum;
		i++;
	}
	mid = (sum / size);
	return (mid);
}

int	counttopusha(int stack[], int mid, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (stack[i] <= mid)
			j++;
		i++;
	}
	return (j);
}

int	counttopushb(int stack[], int mid, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (stack[i] >= mid)
			j++;
		i++;
	}
	return (j);
}

int	chunks(t_pushswap *vars)
{
	int	chunks;
	int	size;

	chunks = 0;
	size = vars->sizea;
	while (size > 2)
	{
		if ((size % 2) != 0)
			size = (size / 2) + 1;
		else
			size = size / 2;
		chunks++;
	}
	return (chunks);
}
