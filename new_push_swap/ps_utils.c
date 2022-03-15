/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 09:06:07 by ben               #+#    #+#             */
/*   Updated: 2022/03/12 09:25:44 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubblesort(int *array, int size)
{
	int	a;
	int	b;
	int	temp;

	a = 0;
	b = 1;
	while (a < size)
		ft_printf("%i\n", array[a++]);
	a = 0;
	while (b != 0)
	{
		b = 0;
		while (a < size)
		{
			if (array[a] > array[a + 1] && a + 1 < size)
			{
				temp = array[a + 1];
				array[a + 1] = array[a];
				array[a] = temp;
				b++;
			}
			a++;
		}
		a = 0;
	}
}

void	indexing(int *arraya, int *arrayb, int size)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < size)
	{
		if (arraya[a] == arrayb[b])
		{
			arraya[a] = b + 1;
			a++;
			b = 0;
		}
		else
			b++;
	}
}

void	cleararray(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
		array[i++] = 0;
}
