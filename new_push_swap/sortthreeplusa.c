/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortthreeplusa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:14:58 by bschende          #+#    #+#             */
/*   Updated: 2022/04/21 12:21:42 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortthreeplusa(t_pushswap *vars)
{
	if (!checkifsorteda(vars))
	{
		if (vars->sta[0] - vars->sta[1] == -2)
			casea1(vars);
		if (vars->sta[0] - vars->sta[1] == -1 && vars->sta[1] > vars->sta[2])
			casea2(vars);
		if (vars->sta[0] - vars->sta[1] == 1 && vars->sta[1] < vars->sta[2])
			swapa(vars);
		if (vars->sta[0] - vars->sta[1] == 2)
			casea3(vars);
		if (vars->sta[0] - vars->sta[1] == 1 && vars->sta[1] > vars->sta[2])
			casea4(vars);
	}
}

void	casea1(t_pushswap *vars)
{
	pushb(vars);
	swapa(vars);
	pusha(vars);
}

void	casea2(t_pushswap *vars)
{
	rotatea(vars);
	swapa(vars);
	pushb(vars);
	rrotatea(vars);
	pusha(vars);
}

void	casea3(t_pushswap *vars)
{
	swapa(vars);
	rotatea(vars);
	swapa(vars);
	rrotatea(vars);
}

void	casea4(t_pushswap *vars)
{
	swapa(vars);
	rotatea(vars);
	swapa(vars);
	pushb(vars);
	rrotatea(vars);
	pusha(vars);
}
