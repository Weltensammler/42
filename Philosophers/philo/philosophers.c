/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:47:23 by bschende          #+#    #+#             */
/*   Updated: 2022/05/11 19:05:09 by bschende         ###   ########.fr       */
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
	varsid = init_varsid(&vars, 0);
	gettime(&vars);
	timepassed(&vars);
	while (i < vars.phils)
		pthread_mutex_init(&varsid[i++].lfork, NULL);
	pthread_mutex_init(&vars.death, NULL);
	init_threads(&vars, varsid);
	while (maindeath(&vars, varsid))
	i = 0;
	while (i < vars.phils)
		pthread_mutex_destroy(&varsid[i++].lfork);
	pthread_mutex_destroy(&varsid->vars->death);
	free(varsid);
	return (0);
}

int	init_vars(int argc, char **argv, t_philosophers *vars)
{
	int	i;

	i = 0;
	vars->phils = ft_atoi(argv[1]);
	vars->ttd = ft_atoi(argv[2]);
	vars->tte = ft_atoi(argv[3]);
	vars->tts = ft_atoi(argv[4]);
	vars->fork = malloc(sizeof(int) * vars->phils);
	vars->todeath = 0;
	vars->who = 0;
	vars->allfull = 0;
	if (argc == 6)
		vars->notte = ft_atoi(argv[5]);
	else if (argc != 6)
		vars->notte = -1;
	while (i < vars->phils)
		vars->fork[i++] = 0;
	return (1);
}

t_philid	*init_varsid(t_philosophers *vars, int i)
{
	t_philid	*varsid;

	varsid = malloc(sizeof(t_philid) * vars->phils);
	while (i < vars->phils)
	{
		varsid[i].id = i + 1;
		varsid[i].vars = vars;
		varsid[i].full = 0;
		varsid[i].leftf = 0;
		varsid[i].i = 0;
		if (i - 1 >= 0)
		{
			varsid[i].rfork = &varsid[i - 1].lfork;
			varsid[i].rightf = &varsid[i - 1].leftf;
		}
		else if (i - 1 < 0)
		{
			varsid[i].rfork = &varsid[vars->phils - 1].lfork;
			varsid[i].rightf = &varsid[vars->phils - 1].leftf;
			if (vars->phils == 1)
				*varsid[i].rightf = 1;
		}
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

void	init_threads(t_philosophers *vars, t_philid *varsid)
{
	int	i;

	i = 0;
	pthread_create(&vars->dead, NULL, (void *)&deathclock, (void *)&varsid[i]);
	pthread_detach(varsid[i].t);
	while (i < vars->phils)
	{
		pthread_create(&varsid[i].t, NULL, (void *)&cycle, (void *)&varsid[i]);
		pthread_detach(varsid[i].t);
		timepassed(vars);
		i = i + 2;
	}
	usleep(1000);
	i = 1;
	while (i < vars->phils)
	{
		pthread_create(&varsid[i].t, NULL, (void *)&cycle, (void *)&varsid[i]);
		pthread_detach(varsid[i].t);
		timepassed(vars);
		i = i + 2;
	}
}
