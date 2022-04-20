/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:02:57 by ben               #+#    #+#             */
/*   Updated: 2022/04/18 15:03:03 by ben              ###   ########.fr       */
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
