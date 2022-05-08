/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:47:23 by bschende          #+#    #+#             */
/*   Updated: 2022/05/02 15:09:52 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philosophers	vars;
	t_philid		*varsid;
	int				i;

	i = 0;
	init_vars(argc, argv, &vars);
	varsid = init_varsid(&vars);
	gettime(&vars);
	timepassed(&vars);
	while (i < vars.phils)
	{
		pthread_create(&varsid[i].t, NULL, &cycle, (void *)&varsid[i]);
		i++;
	}
	i = 0;
	while (i < vars.phils)
		pthread_join(varsid[i++].t, NULL);
	while (!checkifdead(&vars, varsid) && i < vars.notte)
	{
		eating(&vars, varsid);
		sleeping(&vars, varsid);
		thinking(&vars, varsid);
		i++;
	}
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
