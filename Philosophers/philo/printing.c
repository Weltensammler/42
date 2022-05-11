/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:41:56 by bschende          #+#    #+#             */
/*   Updated: 2022/05/11 11:46:13 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	checkinput(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_strchr("-0123456789", argv[i][j]) && j == 0)
				return (0);
			else if (!ft_strchr("0123456789", argv[i][j]) && j > 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	printstate(int what, t_philid *varsid)
{
	pthread_mutex_lock(&varsid->vars->death);
	timepassed(varsid->vars);
	if (what == 1)
		printf("%li	%i	has taken a fork\n", varsid->vars->runtime, varsid->id);
	else if (what == 2)
		printf("%li	%i	is eating\n", varsid->vars->runtime, varsid->id);
	else if (what == 3)
		printf("%li	%i	is sleeping\n", varsid->vars->runtime, varsid->id);
	else if (what == 4)
		printf("%li	%i	is thinking\n", varsid->vars->runtime, varsid->id);
	pthread_mutex_unlock(&varsid->vars->death);
	return (0);
}
