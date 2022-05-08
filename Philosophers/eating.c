/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:55:29 by bschende          #+#    #+#             */
/*   Updated: 2022/05/08 16:30:30 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating(t_philosophers *vars, t_philid *varsid)
{
	timepassed(vars);
	take_forks(&varsid->lfork, varsid->rfork);
	printf("%li	%i	has taken a fork\n", vars->runtime, varsid->ID);
	varsid->starteat = vars->runtime;
	if (!checkifdead(vars, varsid))
		printf("%li	%i	is eating\n", vars->runtime, varsid->ID);
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
		printf("%li	%i	is sleeping\n", vars->runtime, varsid->ID);
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
		printf("%li	%i	is thinking\n", vars->runtime, varsid->ID);
	/*while (vars->runtime < (varsid->startthink + vars->tts))
	{
		timepassed(vars);
		checkifdead(vars, varsid);
		usleep(1000);
		i++;
	}*/
	return (0);
}

int	checkifdead(t_philosophers *vars, t_philid *varsid)
{
	timepassed(vars);
	if (vars->runtime - varsid->starteat > vars->ttd)
	{
		printf("%li	%i	died\n", vars->runtime, varsid->ID);
		exit(0);
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
