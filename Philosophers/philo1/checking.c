/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:09:47 by bschende          #+#    #+#             */
/*   Updated: 2022/05/18 09:38:07 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	checkifdead(t_philosophers *vars, t_philid *varsid)
{
	// pthread_mutex_lock(&varsid->vars->all);
	// nowtime(vars, varsid);
	pthread_mutex_lock(&vars->check);
	if ((gettime() - varsid->nulltime) - varsid->starteat > vars->ttd)
	{
		vars->todeath = 1;
		varsid->ko = 1;
		vars->who = varsid->id;
	}
	pthread_mutex_unlock(&vars->check);
	return (0);
}

int	maindeath(t_philosophers *vars, t_philid *varsid)
{
	int	i;

	while (vars->todeath == 0)
	{
		pthread_mutex_lock(&vars->check);
		i = 0;
		while (i < vars->phils)
		{
			if (varsid[i].full == 1)
				vars->allfull = vars->allfull + 1;
			if (gettime() - vars->timestart - varsid[i].starteat > vars->ttd)
			{
				varsid->vars->todeath = 1;
				varsid->vars->who = varsid[i].id;
				break ;
			}
			i++;
		}
		if (vars->allfull >= vars->phils && vars->todeath != 1)
			break ;
		pthread_mutex_unlock(&vars->check);
	}
	if (vars->todeath == 1)
		printstate(5, varsid);
	return (0);
}

void	timepassed(t_philosophers *vars)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	vars->runtime = ((time.tv_sec * 1000) + \
	(time.tv_usec / 1000)) - vars->timestart;
}

// void	*deathclock(t_philid *varsid)
// {
// 	int	i;

// 	while (varsid->vars->todeath == 0)
// 	{
// 		i = 0;
// 		while (i < varsid->vars->phils)
// 		{
// 			pthread_mutex_lock(&varsid->vars->all);
// 			timepassed(varsid->vars);
// 			pthread_mutex_unlock(&varsid->vars->all);
// 			if (varsid->vars->runtime - varsid[i].starteat > varsid->vars->ttd)
// 			{
// 				varsid->vars->todeath = 1;
// 				varsid->vars->who = varsid[i].id;
// 			}
// 			i++;
// 		}
// 	}
// 	return (NULL);
// }

void	nowtime(t_philosophers *vars, t_philid *varsid)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	varsid->time = ((time.tv_sec * 1000) + \
	(time.tv_usec / 1000)) - vars->timestart;
}
