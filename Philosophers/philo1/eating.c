/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:55:29 by bschende          #+#    #+#             */
/*   Updated: 2022/05/18 11:04:26 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating(t_philosophers *vars, t_philid *varsid)
{
	// pthread_mutex_lock(&vars->all);
	// nowtime(vars, varsid);
	// pthread_mutex_unlock(&vars->all);
	if (!checkifdead(vars, varsid))
	{
		// pthread_mutex_lock(&vars->all);
		take_forks(varsid);
		// pthread_mutex_unlock(&vars->all);
	}
	varsid->starteat = gettime() - varsid->nulltime;
	printf("tte %i\n", vars->tte);
	if (!checkifdead(vars, varsid))
		printstate(2, varsid);
	while (gettime() - varsid->nulltime < (varsid->starteat + vars->tte))
	{
		// pthread_mutex_lock(&vars->all);
		// nowtime(vars, varsid);
		// pthread_mutex_unlock(&vars->all);
		checkifdead(vars, varsid);
		usleep(1000);
	}
	printf("nulltime %li, starteat %li, tte %i\n", varsid->nulltime, varsid->starteat, vars->tte);
	varsid->full++;
	free_forks(varsid);
	return (0);
}

void	take_forks(t_philid *varsid)
{
	while (varsid->leftf != 0 || *varsid->rightf != 0)
	{
		usleep(1000);
	}
	// pthread_mutex_lock(&varsid->lfork);
	// pthread_mutex_lock(varsid->rfork);
	// if (varsid->leftf == 0 && *varsid->rightf == 0)
	// {
	pthread_mutex_lock(&varsid->lfork);
	pthread_mutex_lock(varsid->rfork);
	varsid->leftf = 1;
	*varsid->rightf = 1;
	printstate(1, varsid);
	printstate(1, varsid);
	// }
}

void	free_forks(t_philid *varsid)
{
	varsid->leftf = 0;
	*varsid->rightf = 0;
	pthread_mutex_unlock(&varsid->lfork);
	pthread_mutex_unlock(varsid->rfork);
}
