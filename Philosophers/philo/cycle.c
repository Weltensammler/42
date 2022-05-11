/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:06:26 by bschende          #+#    #+#             */
/*   Updated: 2022/05/11 18:21:05 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*cycle(t_philid *varsid)
{
	while (!checkifdead(varsid->vars, varsid))
	{
		eating(varsid->vars, varsid);
		sleeping(varsid->vars, varsid);
		thinking(varsid->vars, varsid);
		varsid->i++;
		if (varsid->i == varsid->vars->notte)
			varsid->full = 1;
	}
	return (NULL);
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
	usleep(3000);
	return (0);
}
