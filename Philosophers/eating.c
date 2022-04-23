/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:55:29 by bschende          #+#    #+#             */
/*   Updated: 2022/04/23 21:58:41 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating(t_philosophers *vars, t_philid *varsid)
{
	timepassed(vars);
	varsid->starteat = vars->runtime;
	printf("Test starteat %li\n", varsid->starteat);
	if (!checkifdead(vars, varsid))
		printf("%li	%i	is eating\n", vars->runtime, varsid->ID);
	while (vars->runtime < (varsid->starteat + vars->tte))
	{
		timepassed(vars);
		checkifdead(vars, varsid);
		usleep(1000);
	}
	printf("%li	%i	is done eating\n", vars->runtime, varsid->ID);
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
	printf("%li	%i	is done sleeping\n", vars->runtime, varsid->ID);
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
	while (vars->runtime < (varsid->startthink + vars->tts))
	{
		timepassed(vars);
		checkifdead(vars, varsid);
		usleep(1000);
		i++;
	}
	printf("%li	%i	is done thinking\n", vars->runtime, varsid->ID);
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
