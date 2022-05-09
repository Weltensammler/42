/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:55:29 by bschende          #+#    #+#             */
/*   Updated: 2022/05/09 14:07:11 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating(t_philosophers *vars, t_philid *varsid)
{
	timepassed(vars);
	take_forks(&varsid->lfork, varsid->rfork);
	printstate(1, varsid);
	varsid->starteat = vars->runtime;
	if (!checkifdead(vars, varsid))
		printstate(2, varsid);
	while (vars->runtime < (varsid->starteat + vars->tte))
	{
		timepassed(vars);
		checkifdead(vars, varsid);
		usleep(1000);
	}
	free_forks(&varsid->lfork, varsid->rfork);
	return (0);
}

int	sleeping(t_philosophers *vars, t_philid *varsid)
{
	int	i;

	i = 0;
	timepassed(vars);
	varsid->startsleep = vars->runtime;
	if (!checkifdead(vars, varsid))
		printstate(3, varsid);
	while (vars->runtime < (varsid->startsleep + vars->tts))
	{
		timepassed(vars);
		checkifdead(vars, varsid);
		usleep(1000);
		i++;
	}
	return (0);
}

int	thinking(t_philosophers *vars, t_philid *varsid)
{
	int	i;

	i = 0;
	timepassed(vars);
	varsid->startthink = vars->runtime;
	if (!checkifdead(vars, varsid))
		printstate(4, varsid);
	return (0);
}

int	checkifdead(t_philosophers *vars, t_philid *varsid)
{
	timepassed(vars);
	if (vars->runtime - varsid->starteat > vars->ttd)
	{
		vars->todeath = 1;
		// printf("%li	%i	died\n", vars->runtime, varsid->ID);
		// exit(0);
	}
	return (0);
}

void	take_forks(pthread_mutex_t *lfork, pthread_mutex_t *rfork)
{
	pthread_mutex_lock(lfork);
	pthread_mutex_lock(rfork);
}

void	free_forks(pthread_mutex_t *lfork, pthread_mutex_t *rfork)
{
	pthread_mutex_unlock(lfork);
	pthread_mutex_unlock(rfork);
}
