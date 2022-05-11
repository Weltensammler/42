/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:09:47 by bschende          #+#    #+#             */
/*   Updated: 2022/05/11 11:12:05 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	checkifdead(t_philosophers *vars, t_philid *varsid)
{
	timepassed(vars);
	if (vars->runtime - varsid->starteat > vars->ttd)
	{
		vars->todeath = 1;
	}
	return (0);
}

void	timepassed(t_philosophers *vars)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	vars->runtime = ((time.tv_sec * 1000) + \
	(time.tv_usec / 1000)) - vars->timestart;
}
