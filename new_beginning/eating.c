/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:55:29 by bschende          #+#    #+#             */
/*   Updated: 2022/05/18 15:00:27 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating(t_philosophers *vars, t_philid *varsid)
{
	pthread_mutex_lock(&vars->all);
	pthread_mutex_unlock(&vars->all);
	if (!checkifdead(vars, varsid))
		take_forks(varsid);
	pthread_mutex_lock(&vars->check);
	varsid->starteat = gettime() - varsid->nulltime;
	pthread_mutex_unlock(&vars->check);
	if (!checkifdead(vars, varsid))
		printstate(2, varsid);
	// varsid->starteat = vars->runtime;
	while (gettime() - varsid->nulltime < (varsid->starteat + vars->tte))
	{
		checkifdead(vars, varsid);
		usleep(1000);
	}
	varsid->eatcount++;
	if (varsid->eatcount == vars->notte)
	{
		pthread_mutex_lock(&varsid->vars->check);
		varsid->full = 1;
		pthread_mutex_unlock(&varsid->vars->check);
	}
	free_forks(varsid);
	// printf("eating Ok %i\n", varsid->id);
	return (0);
}

void	take_forks(t_philid *varsid)
{
	// while (varsid->leftf != 0 || *varsid->rightf != 0)
	// {
	// 	usleep(1000);
	// }
	// if (varsid->leftf == 0 && *varsid->rightf == 0)
	// {
	if (varsid->test != 1 && varsid->vars->stop != 1)
	{
		pthread_mutex_lock(&varsid->lfork);
		pthread_mutex_lock(varsid->rfork);
		*varsid->rightf = 1;
		varsid->leftf = 1;
		printstate(1, varsid);
		printstate(1, varsid);
	}
	// }
}

void	free_forks(t_philid *varsid)
{
	if (varsid->test != 1 && varsid->vars->stop != 1)
	{
		varsid->leftf = 0;
		*varsid->rightf = 0;
		pthread_mutex_unlock(&varsid->lfork);
		pthread_mutex_unlock(varsid->rfork);
	}
}
