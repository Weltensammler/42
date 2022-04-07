/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:44:34 by ben               #+#    #+#             */
/*   Updated: 2022/04/06 12:15:37 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapab(int *arraya, int *arrayb, int *sizea, int *sizeb)
{
	int	temp;

	if (*sizea > 1 && *sizeb > 1)
	{
		temp = arraya[0];
		arraya[0] = arraya[1];
		arraya[1] = temp;
		temp = arrayb[0];
		arrayb[0] = arrayb[1];
		arrayb[1] = temp;
		write(1, "ss\n", 3);
	}
}

void	rotateab(int *arraya, int *sizea, int *arrayb, int *sizeb)
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
	i = 0;
	temp = arrayb[0];
	while (i < (*sizeb - 1))
	{
		arrayb[i] = arrayb[i + 1];
		i++;
	}
	arrayb[*sizeb - 1] = temp;
	write(1, "rr\n", 3);
}

void	rrotateab(int *arraya, int *sizea, int *arrayb, int *sizeb)
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
