/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:06:23 by bschende          #+#    #+#             */
/*   Updated: 2022/04/12 17:50:10 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_pushswap *vars)
{
	int	mid;

	if ((vars->sizea % 2) != 0)
			mid = (vars->sizea / 2) + 1;
	else
		mid = vars->sizea / 2;
	while (vars->sizea > mid)
	{
		if (vars->sta[0] < mid)
		{
			pushb(vars);
			if (vars->sizea > mid)
				sorting(vars);
		}
		if (vars->sta[vars->sizea - 1] < mid)
		{
			rrotatea(vars);
			pushb(vars);
			if (vars->sizea > mid)
				sorting(vars);
		}
		else
			rotatea(vars);
	}
	if (checkifsorteda(vars))
		pusha(vars);
	if (!checkifsorteda(vars))
	{
		rotatea(vars);
		pusha(vars);
	}
}

void	chunking(t_pushswap *vars)
{
	int	mid;
	int	topush;

	mid = findmid(vars->sta, vars->sizea);
	topush = counttopush(vars->sta, mid, vars->sizea);
	topush = vars->sizea - topush;
	while (vars->sizea >= topush)
	{
		ft_printf("\n%i\n", topush);
		if (vars->sta[0] <= mid)
		{
			pushb(vars);
			// if (vars->sizea > mid)
			// 	sorting(vars);
		}
		else if (vars->sta[vars->sizea - 1] <= mid)
		{
			rrotatea(vars);
			pushb(vars);
			// if (vars->sizea > mid)
			// 	sorting(vars);
		}
		else
			rotatea(vars);
	}
}

int	checkifsorteda(t_pushswap *vars)
{
	int	i;

	i = 0;
	while (i + 1 < vars->sizea)
	{
		if (vars->sta[i] < vars->sta[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	checkifsortedb(t_pushswap *vars)
{
	int	i;

	i = 0;
	while (i + 1 < vars->sizeb)
	{
		if (vars->stb[i] > vars->stb[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	sortthreea(t_pushswap *vars)
{
	if (!checkifsorteda(vars))
	{
		if (vars->sta[0] - vars->sta[1] == -2)
		{
			rrotatea(vars);
			swapa(vars);
		}
		if (vars->sta[0] - vars->sta[1] == -1 && vars->sta[1] > vars->sta[2])
			rrotatea(vars);
		if (vars->sta[0] - vars->sta[1] == 1 && vars->sta[1] < vars->sta[2])
			swapa(vars);
		if (vars->sta[0] - vars->sta[1] == 2)
			rotatea(vars);
		if (vars->sta[0] - vars->sta[1] == 1 && vars->sta[1] > vars->sta[2])
		{
			swapa(vars);
			rrotatea(vars);
		}
	}
}

void	sortfive(t_pushswap *vars)
{
	while (vars->sizea > 3)
	{
		if (vars->sta[0] < 3)
			pushb(vars);
		if (vars->sta[vars->sizea - 1] < 3)
		{
			rrotatea(vars);
			pushb(vars);
		}
		else
			rotatea(vars);
	}
	sortthreea(vars);
	if (vars->stb[0] > vars->stb[1])
	{
		pusha(vars);
		pusha(vars);
	}
	if (vars->stb[0] < vars->stb[1])
	{
		rotateb(vars);
		pusha(vars);
		pusha(vars);
	}
}

void	sortthreeplusa(t_pushswap *vars)
{
	if (!checkifsorteda(vars))
	{
		if (vars->sta[0] - vars->sta[1] == -2)
		{
			pushb(vars);
			swapa(vars);
			pusha(vars);
		}
		if (vars->sta[0] - vars->sta[1] == -1 && vars->sta[1] > vars->sta[2])
		{
			rotatea(vars);
			swapa(vars);
			pushb(vars);
			rrotatea(vars);
			pusha(vars);
		}
		if (vars->sta[0] - vars->sta[1] == 1 && vars->sta[1] < vars->sta[2])
			swapa(vars);
		if (vars->sta[0] - vars->sta[1] == 2)
		{
			swapa(vars);
			rotatea(vars);
			swapa(vars);
			rrotatea(vars);
		}
		if (vars->sta[0] - vars->sta[1] == 1 && vars->sta[1] > vars->sta[2])
		{
			swapa(vars);
			rotatea(vars);
			swapa(vars);
			pushb(vars);
			rrotatea(vars);
			pusha(vars);
		}
	}
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
