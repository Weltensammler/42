/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:06:26 by bschende          #+#    #+#             */
/*   Updated: 2022/05/18 15:47:35 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*cycle(t_philid *varsid)
{
	// int	i;

	// i = 0;
	while (!varsid->vars->todeath)
	{
		eating(varsid->vars, varsid);
		if (varsid->full == 1 || varsid->vars->stop == 1)
			return (NULL);
		sleeping(varsid->vars, varsid);
		if (varsid->vars->stop == 1)
			return (NULL);
		thinking(varsid->vars, varsid);
		if (varsid->vars->stop == 1)
			return (NULL);
		// i++;
		// if (i == varsid->vars->notte)
		// {
		// 	pthread_mutex_lock(&varsid->vars->check);
		// 	varsid->full = 1;
		// 	pthread_mutex_unlock(&varsid->vars->check);
		// }
	}
	return (NULL);
}

int	sleeping(t_philosophers *vars, t_philid *varsid)
{
	varsid->startsleep = gettime() - varsid->nulltime;
	if (!checkifdead(vars, varsid))
		printstate(3, varsid);
	while (gettime() - varsid->nulltime < (varsid->startsleep + vars->tts))
	{
		checkifdead(vars, varsid);
		usleep(1000);
	}
	return (0);
}

int	thinking(t_philosophers *vars, t_philid *varsid)
{
	varsid->startthink = gettime() - varsid->nulltime;
	if (!checkifdead(vars, varsid))
		printstate(4, varsid);
	usleep(5000);
	return (0);
}
