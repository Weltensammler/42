/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:06:23 by bschende          #+#    #+#             */
/*   Updated: 2022/04/13 16:05:08 by bschende         ###   ########.fr       */
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

int	chunkinga(t_pushswap *vars)
{
	int	mid;
	int	topush;
	int	i;

	
	i = 0;
	mid = findmid(vars->sta, vars->sizea);
	topush = counttopush(vars->sta, mid, vars->sizea);
	while (i < topush)
	{
		ft_printf("\n%ito push (chunkinga)\n", topush);
		if (vars->sta[0] <= mid)
		{
			pushb(vars);
			i++;
		}
		else if (vars->sta[vars->sizea - 1] <= mid)
		{
			rrotatea(vars);
			pushb(vars);
			i++;
		}
		else
			rotatea(vars);
	}
	return (topush);
}

int	chunkingplusb(int stack[], int size, t_pushswap *vars)
{
	int	mid;
	int	topush;
	int	i;
	int	j;

	
	i = 0;
	j = 0;
	mid = findmid(stack, size);
	topush = counttopush(stack, mid, size);
	while (i < topush)
	{
		//ft_printf("\n%i\n", topush);
		if (stack[0] >= mid)
		{
			pusha(vars);
			i++;
		}
		else
		{
			rotateb(vars);
			j++;
		}
	}
	while (j > 0)
	{
		rrotateb(vars);
		j--;
	}
	return (topush);
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

int	checkifsortedplus(int stack[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] > stack[i + 1])
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
