/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:06:26 by bschende          #+#    #+#             */
/*   Updated: 2022/05/13 18:42:30 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*cycle(t_philid *varsid)
{
	int	i;

	i = 0;
	while (!varsid->ko)
	{
		eating(varsid->vars, varsid);
		// if (i + 1 == varsid->vars->notte)
		// 	varsid->full = 1;
		sleeping(varsid->vars, varsid);
		thinking(varsid);
		i++;
	}
	return (NULL);
}

int	sleeping(t_philosophers *vars, t_philid *varsid)
{
	varsid->startsleep = gettime() - varsid->nulltime;
	if (!varsid->ko)
		printstate(3, varsid);
	while (gettime() - varsid->nulltime < (varsid->startsleep + vars->tts))
	{
		checkifdead(vars, varsid);
		usleep(1000);
	}
	return (0);
}

int	thinking(t_philid *varsid)
{
	varsid->startthink = gettime() - varsid->nulltime;
	if (!varsid->ko)
		printstate(4, varsid);
	usleep(3000);
	return (0);
}
