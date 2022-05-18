/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:06:26 by bschende          #+#    #+#             */
/*   Updated: 2022/05/12 17:22:00 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*cycle(t_philid *varsid)
{
	int	i;

	i = 0;
	while (!varsid->vars->todeath)
	{
		eating(varsid->vars, varsid);
		sleeping(varsid->vars, varsid);
		thinking(varsid->vars, varsid);
		i++;
		if (i == varsid->vars->notte)
			varsid->full = 1;
	}
	return (NULL);
}

int	sleeping(t_philosophers *vars, t_philid *varsid)
{
	timepassed(vars);
	varsid->startsleep = vars->runtime;
	if (!checkifdead(vars, varsid))
		printstate(3, varsid);
	while (vars->runtime < (varsid->startsleep + vars->tts))
	{
		timepassed(vars);
		checkifdead(vars, varsid);
		usleep(1000);
	}
	return (0);
}

int	thinking(t_philosophers *vars, t_philid *varsid)
{
	timepassed(vars);
	varsid->startthink = vars->runtime;
	if (!checkifdead(vars, varsid))
		printstate(4, varsid);
	usleep(5000);
	return (0);
}
