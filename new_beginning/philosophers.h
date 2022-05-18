/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:51:15 by bschende          #+#    #+#             */
/*   Updated: 2022/05/12 17:04:09 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philosophers
{
	pthread_t		dead;
	int				phils;
	int				ttd;
	int				tte;
	int				tts;
	int				notte;
	int				todeath;
	int				who;
	int				allfull;
	pthread_mutex_t	death;
	pthread_mutex_t	all;
	long int		timestart;
	long int		runtime;
}	t_philosophers;

typedef struct s_philid
{
	int				id;
	long int		starteat;
	long int		startsleep;
	long int		startthink;
	long int		time;
	int				full;
	int				leftf;
	int				*rightf;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	lfork;
	pthread_t		t;
	t_philosophers	*vars;
}	t_philid;

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			init_vars(int argc, char **argv, t_philosophers *vars);
t_philid	*init_varsid(t_philosophers *vars, int i);
void		gettime(t_philosophers *vars);
void		timepassed(t_philosophers *vars);
int			eating(t_philosophers *vars, t_philid *varsid);
int			sleeping(t_philosophers *vars, t_philid *varsid);
int			thinking(t_philosophers *vars, t_philid *varsid);
int			checkifdead(t_philosophers *vars, t_philid *varsid);
void		*cycle(t_philid *varsid);
void		take_forks(t_philid *varsid);
void		free_forks(t_philid *varsid);
int			checkinput(int argc, char **argv);
int			ft_strchr(const char *str, int c);
int			printstate(int what, t_philid *philid);
void		init_threads(t_philosophers *vars, t_philid *varsid);
int			maindeath(t_philosophers *vars, t_philid *varsid);
void		*deathclock(t_philid *varsid);
void		nowtime(t_philosophers *vars, t_philid *varsid);

#endif
