/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:49:37 by bschende          #+#    #+#             */
/*   Updated: 2022/04/12 16:04:19 by bschende         ###   ########.fr       */
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
	ft_printf("%i, %i, %i, %i\n", stack[0], stack[1], stack[2], mid);
	return (mid);
}

int	counttopush(int stack[], int mid, int size)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (stack[i] < mid)
			j++;
		i++;
	}
	return (j);
}
