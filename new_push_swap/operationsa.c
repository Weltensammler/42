/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:03:18 by ben               #+#    #+#             */
/*   Updated: 2022/03/12 13:46:24 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapa(int *array)
{
	int	temp;

	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
	write(1, "sa\n", 3);
}

void	pushb(int *arraya, int *arrayb, int size)
{
	int	temp;
	int	i;

	i = 0;
	temp = arraya[0];
	while (i < size)
	{
		arraya[i] = arraya[i + 1];
		i++;
	}
	arraya[size] = 0;
	while (size >= 0)
	{
		arrayb[size] = arrayb[size - 1];
		size--;
	}
	arrayb[0] = temp;
	write(1, "pb\n", 3);
}
