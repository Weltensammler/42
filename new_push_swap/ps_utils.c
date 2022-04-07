/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 09:06:07 by ben               #+#    #+#             */
/*   Updated: 2022/04/07 20:13:38 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubblesort(t_pushswap *vars)
{
	int	a;
	int	b;
	int	temp;

	a = 0;
	b = 1;
	while (a < vars->size)
		ft_printf("%i\n", vars->arrayb[a++]);
	a = 0;
	while (b != 0)
	{
		b = 0;
		while (a < vars->size)
		{
			if (vars->arrayb[a] > vars->arrayb[a + 1] && a + 1 < vars->size)
			{
				temp = vars->arrayb[a + 1];
				vars->arrayb[a + 1] = vars->arrayb[a];
				vars->arrayb[a] = temp;
				b++;
			}
			a++;
		}
		a = 0;
	}
}

void	indexing(t_pushswap *vars)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < vars->size)
	{
		if (vars->arraya[a] == vars->arrayb[b])
		{
			vars->arraya[a] = b + 1;
			a++;
			b = 0;
		}
		else
			b++;
	}
}

void	cleararray(t_pushswap *vars)
{
	int	i;

	i = 0;
	while (i < vars->size)
		vars->arrayb[i++] = 0;
}
