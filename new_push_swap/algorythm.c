/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:06:23 by bschende          #+#    #+#             */
/*   Updated: 2022/04/08 19:01:09 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_pushswap *vars)
{
	int	i;
	int	mid;

	i = 0;
	if ((vars->sizea % 2) != 0)
			mid = (vars->sizea / 2) + 1;
		else
			mid = vars->sizea / 2;
	while (i < vars->sizea - 2)
	{
		if (vars->arraya[i] < mid)
		{
			pushb(vars);
			if (vars->sizea > 2)
				sorting(vars);
			i++;
		}
		if (vars->arraya[vars->sizea - 1] < mid)
		{
			rrotatea(vars);
			pushb(vars);
			if (vars->sizea > 2)
				sorting(vars);
			i++;
		}
		else
			rotatea(vars);
	}
	if (checkifsorteda(vars))
	{
		pusha(vars);
	}
	if (!checkifsorteda(vars))
	{
		rotatea(vars);
		pusha(vars);
	}
}

int	checkifsorteda(t_pushswap *vars)
{
	int	i;

	i = 0;
	while (i + 1 < vars->sizea)
	{
		if (vars->arraya[i] < vars->arraya[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
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
