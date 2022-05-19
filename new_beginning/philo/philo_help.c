/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:34:47 by bschende          #+#    #+#             */
/*   Updated: 2022/05/19 11:09:13 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	detach(t_philosophers *vars, t_philid *varsid)
{
	int	i;

	i = 0;
	while (i < vars->phils)
	{
		pthread_detach(varsid[i].t);
		i++;
	}
}

void	join(t_philosophers *vars, t_philid *varsid)
{
	int	i;

	i = 0;
	while (i < vars->phils)
	{
		pthread_join(varsid[i].t, NULL);
		i++;
	}
}

void	detachorjoin(t_philosophers *vars, t_philid *varsid)
{
	// if (vars->todeath == 1)
	// 	detach(vars, varsid);
	// else
	join(vars, varsid);
}

void	initzero(t_philid *varsid, int phil)
{
	int	i;

	i = 0;
	while (i < phil)
	{
		varsid[i].full = 0;
		varsid[i].leftf = 0;
		varsid[i].starteat = 0;
		varsid[i].eatcount = 0;
		i++;
	}
}
