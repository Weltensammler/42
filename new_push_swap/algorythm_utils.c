/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:49:37 by bschende          #+#    #+#             */
/*   Updated: 2022/04/17 23:17:31 by ben              ###   ########.fr       */
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
	//ft_printf("%i, %i, %i, %i\n", stack[0], stack[1], stack[2], mid);
	return (mid);
}

int	counttopusha(int stack[], int mid, int size)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (stack[i] <= mid)
			j++;
		i++;
		printf("\n%i	stack	%i	mid	%i	size	%i	j (counttopush)", stack[i - 1], mid, size, j);
	}
	printf("\n%i\n", j);
	return (j);
}

int	counttopushb(int stack[], int mid, int size)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (stack[i] >= mid)
			j++;
		i++;
		printf("\n%i	stack	%i	mid	%i	size	%i	j (counttopush)", stack[i - 1], mid, size, j);
	}
	printf("\n%i\n", j);
	return (j);
}
