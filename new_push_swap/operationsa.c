/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:03:18 by ben               #+#    #+#             */
/*   Updated: 2022/04/06 12:14:06 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapa(int *array, int *sizea)
{
	int	temp;

	if (*sizea > 1)
	{
		temp = array[0];
		array[0] = array[1];
		array[1] = temp;
		write(1, "sa\n", 3);
	}
}

void	pusha(int *arraya, int *arrayb, int *sizea, int *sizeb)
{
	int	temp;
	int	i;

	i = 0;
	ft_printf("\n		%i	%i\n",*sizea, *sizeb);
	temp = arrayb[0];
	if (*sizeb > 0)
	{
		while (i < (*sizeb - 1))
		{
			arrayb[i] = arrayb[i + 1];
			i++;
		}
		arrayb[*sizeb - 1] = 0;
		i = (*sizeb + *sizea);
		while (i >= 2)
		{
			arraya[i - 1] = arraya[i - 2];
			i--;
		}
		arraya[0] = temp;
		write(1, "pa\n", 3);
		*sizeb = *sizeb - 1;
		*sizea = *sizea + 1;
	}
}

void	rotatea(int *arraya, int *sizea)
{
	int	temp;
	int	i;

	i = 0;
	temp = arraya[0];
	while (i < (*sizea - 1))
	{
		arraya[i] = arraya[i + 1];
		i++;
	}
	arraya[*sizea - 1] = temp;
	write(1, "ra\n", 3);
}

void	rrotatea(int *arraya, int *sizea)
{
	int	temp;
	int	i;

	i = (*sizea - 1);
	temp = arraya[i];
	while (i > 0)
	{
		arraya[i] = arraya[i - 1];
		i--;
	}
	arraya[0] = temp;
	write(1, "rra\n", 4);
}
