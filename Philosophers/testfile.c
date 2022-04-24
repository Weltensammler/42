/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:51:45 by bschende          #+#    #+#             */
/*   Updated: 2022/04/24 13:59:27 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philosophers
{
	pthread_t		*philos;
	int				phils;
	int				ttd;
	int				tte;
	int				tts;
	int				notte;
	int				time;
	int				*fork;
	long int		timestart;
	long int		runtime;
}	t_philosophers;

typedef struct s_philid
{
	// mutex
	int				ID;
	long int		starteat;
	long int		startsleep;
	long int		startthink;
	pthread_t		*t;
	t_philosophers	*vars;
}	t_philid;

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	value;
	int	sign;

	i = 0;
	value = 0;
	sign = 1;
	while (*(str + i) == ' ' || (*(str + i) >= 9 && *(str + i) <= 13))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
		sign = 1 - 2 * (str[i++] == '-');
	else if (*str == '\0')
		return (0);
	while (ft_isdigit(*(str + i)))
		value = value * 10 + *(str + i++) - '0';
	return ((int)(sign * value));
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
	vars->timestart = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
}

void	timepassed(t_philosophers *vars)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	vars->runtime = ((time.tv_sec * 1000) + (time.tv_usec / 1000)) - vars->timestart;
}

void	*cycle(void *varsid)
{
	int			i;
	t_philid *	newid;

	i = 0;
	newid = varsid;
	while (i < newid->vars->phils)
	{
		printf("Test ID %i", newid[i].ID);
		i++;
	}
	return (NULL);
}


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
	printf("OK phils %i", vars.phils);
	while (i < vars.phils)
	{
		pthread_create(varsid[i].t, NULL, &cycle, (void *)&varsid[i]);
		i++;
	}
	i = 0;
	while (i < vars.phils)
	{
		pthread_join(*varsid[i].t, NULL);
		i++;
	}
	return (0);
}
