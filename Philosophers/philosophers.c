/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:47:23 by bschende          #+#    #+#             */
/*   Updated: 2022/05/09 16:00:31 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philosophers	vars;
	t_philid		*varsid;
	int				i;

	i = 0;
	if (!checkinput(argc, argv))
	{
		printf("Error, wrong input");
		return (0);
	}
	init_vars(argc, argv, &vars);
	varsid = init_varsid(&vars);
	gettime(&vars);
	timepassed(&vars);
	while (i < vars.phils)
	{
		pthread_mutex_init(&varsid[i].lfork, NULL);
		i++;
	}
	pthread_mutex_init(&vars.death, NULL);
	i = 0;
	while (i < vars.phils)
	{
		pthread_create(&varsid[i].t, NULL, (void *)&cycle, (void *)&varsid[i]);
		pthread_detach(varsid[i].t);
		timepassed(&vars);
		i = i + 2;
	}
	i = 1;
	while (i < vars.phils)
	{
		pthread_create(&varsid[i].t, NULL, (void *)&cycle, (void *)&varsid[i]);
		pthread_detach(varsid[i].t);
		timepassed(&vars);
		i = i + 2;
	}
	while (vars.todeath == 0)
	{
		i = 0;
		while (i < vars.phils)
		{
			if (varsid[i].full == 1)
				vars.allfull = vars.allfull + 1;
			i++;
		}
		if (vars.allfull >= vars.phils)
			break ;
	}
	pthread_mutex_lock(&varsid->vars->death);
	if (vars.todeath == 1)
		printf("%li	%i	died\n", vars.runtime, varsid->ID);
	// i = 0;
	// while (i < vars.phils)
	// 	pthread_join(varsid[i++].t, NULL);
	i = 0;
	while (i < vars.phils)
	{
		pthread_mutex_destroy(&varsid[i].lfork);
		i++;
	}
	pthread_mutex_destroy(&varsid->vars->death);
	return (0);
}

int	init_vars(int argc, char **argv, t_philosophers *vars)
{
	int				i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (0);
	vars->phils = ft_atoi(argv[1]);
	vars->ttd = ft_atoi(argv[2]);
	vars->tte = ft_atoi(argv[3]);
	vars->tts = ft_atoi(argv[4]);
	vars->fork = malloc(sizeof(int) * vars->phils);
	vars->todeath = 0;
	vars->allfull = 0;
	if (argc == 6)
		vars->notte = ft_atoi(argv[5]);
	while (i < vars->phils)
		vars->fork[i++] = 0;
	return (1);
}

t_philid	*init_varsid(t_philosophers *vars)
{
	t_philid	*varsid;
	int			i;

	i = 0;
	varsid = malloc(sizeof(t_philid) * vars->phils);
	while (i < vars->phils)
	{
		varsid[i].ID = i + 1;
		varsid[i].vars = vars;
		varsid[i].full = 0;
		if (i - 1 >= 0)
			varsid[i].rfork = &varsid[i - 1].lfork;
		else if (i - 1 < 0)
			varsid[i].rfork = &varsid[vars->phils - 1].lfork;
		i++;
	}
	return (varsid);
}

void	gettime(t_philosophers *vars)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	vars->timestart = (current_time.tv_sec * 1000) + \
	(current_time.tv_usec / 1000);
}

void	timepassed(t_philosophers *vars)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	vars->runtime = ((time.tv_sec * 1000) + \
	(time.tv_usec / 1000)) - vars->timestart;
}
