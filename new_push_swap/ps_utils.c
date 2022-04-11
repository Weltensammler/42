/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 09:06:07 by ben               #+#    #+#             */
/*   Updated: 2022/04/11 15:37:17 by bschende         ###   ########.fr       */
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
	// while (a < vars->size)
	// 	ft_printf("%i\n", vars->arrayb[a++]);
	a = 0;
	while (b != 0)
	{
		b = 0;
		while (a < vars->size)
		{
			if (vars->stb[a] > vars->stb[a + 1] && a + 1 < vars->size)
			{
				temp = vars->stb[a + 1];
				vars->stb[a + 1] = vars->stb[a];
				vars->stb[a] = temp;
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
		if (vars->sta[a] == vars->stb[b])
		{
			vars->sta[a] = b + 1;
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
		vars->stb[i++] = 0;
}
