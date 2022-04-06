/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:10:43 by ben               #+#    #+#             */
/*   Updated: 2022/03/17 13:43:24 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapb(int *array)
{
	int	temp;

	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
	write(1, "sb\n", 3);
}

void	pushb(int *arraya, int *arrayb, int *sizea, int *sizeb)
{
	int	temp;
	int	i;

	i = 0;
	ft_printf("\n		%i	%i\n",*sizea, *sizeb);
	temp = arraya[0];
	if (*sizea > 0)
	{
		while (i < (*sizea - 1))
		{
			arraya[i] = arraya[i + 1];
			i++;
		}
		arraya[*sizea - 1] = 0;
		i = (*sizeb + *sizea);
		while (i >= 2)
		{
			arrayb[i - 1] = arrayb[i - 2];
			i--;
		}
		arrayb[0] = temp;
		write(1, "pb\n", 3);
		*sizeb = *sizeb + 1;
		*sizea = *sizea - 1;
	}
}

void	rotateb(int *arrayb, int *sizeb)
{
	int	temp;
	int	i;

	i = 0;
	temp = arrayb[0];
	while (i < (*sizeb - 1))
	{
		arrayb[i] = arrayb[i + 1];
		i++;
	}
	arrayb[*sizeb - 1] = temp;
	write(1, "rb\n", 3);
}

void	rrotateb(int *arrayb, int *sizeb)
{
	int	temp;
	int	i;

	i = (*sizeb - 1);
	temp = arrayb[i];
	while (i > 0)
	{
		arrayb[i] = arrayb[i - 1];
		i--;
	}
	arrayb[0] = temp;
	write(1, "rrb\n", 4);
}
