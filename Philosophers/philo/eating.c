/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:55:29 by bschende          #+#    #+#             */
/*   Updated: 2022/05/11 17:05:28 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating(t_philosophers *vars, t_philid *varsid)
{
	timepassed(vars);
	take_forks(varsid);
	timepassed(vars);
	if (!checkifdead(vars, varsid))
		printstate(2, varsid);
	varsid->starteat = vars->runtime;
	while (vars->runtime < (varsid->starteat + vars->tte))
	{
		timepassed(vars);
		checkifdead(vars, varsid);
		usleep(1000);
	}
	free_forks(varsid);
	return (0);
}

void	take_forks(t_philid *varsid)
{
	while (varsid->leftf != 0 || *varsid->rightf != 0)
	{
		usleep(1000);
	}
	if (varsid->leftf == 0 && *varsid->rightf == 0)
	{
		pthread_mutex_lock(&varsid->lfork);
		varsid->leftf = 1;
		pthread_mutex_lock(varsid->rfork);
		*varsid->rightf = 1;
		printstate(1, varsid);
		printstate(1, varsid);
	}
}

void	free_forks(t_philid *varsid)
{
	pthread_mutex_unlock(&varsid->lfork);
	varsid->leftf = 0;
	pthread_mutex_unlock(varsid->rfork);
	*varsid->rightf = 0;
}
