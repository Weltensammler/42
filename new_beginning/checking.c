/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:09:47 by bschende          #+#    #+#             */
/*   Updated: 2022/05/12 17:16:01 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	checkifdead(t_philosophers *vars, t_philid *varsid)
{
	timepassed(vars);
	if (vars->runtime - varsid->starteat > vars->ttd)
	{
		vars->todeath = 1;
		vars->who = varsid->id;
	}
	return (0);
}

int	maindeath(t_philosophers *vars, t_philid *varsid)
{
	int	i;

	while (vars->todeath == 0)
	{
		timepassed(vars);
		i = 0;
		while (i < vars->phils)
		{
			if (varsid[i].full == 1)
				vars->allfull = vars->allfull + 1;
			i++;
		}
		if (vars->allfull >= vars->phils)
			break ;
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

void	*deathclock(t_philid *varsid)
{
	int	i;

	while (varsid->vars->todeath == 0)
	{
		i = 0;
		while (i < varsid->vars->phils)
		{
			timepassed(varsid->vars);
			if (varsid->vars->runtime - varsid[i].starteat > varsid->vars->ttd)
			{
				varsid->vars->todeath = 1;
				varsid->vars->who = varsid[i].id;
			}
			i++;
		}
	}
	return (NULL);
}

// void	nowtime(t_philosophers *vars, t_philid *varsid)
// {
// 	struct timeval	time;

// 	gettimeofday(&time, NULL);
// 	varsid->time = ((time.tv_sec * 1000) + \
// 	(time.tv_usec / 1000)) - vars->timestart;
// }
