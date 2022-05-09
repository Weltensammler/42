/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:51:15 by bschende          #+#    #+#             */
/*   Updated: 2022/05/09 15:07:43 by bschende         ###   ########.fr       */
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
	pthread_t		*philos;
	int				phils;
	int				ttd;
	int				tte;
	int				tts;
	int				notte;
	int				todeath;
	int				allfull;
	pthread_mutex_t	death;
	int				*fork;
	long int		timestart;
	long int		runtime;
}	t_philosophers;

typedef struct s_philid
{
	int				ID;
	long int		starteat;
	long int		startsleep;
	long int		startthink;
	int				full;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	lfork;
	pthread_t		t;
	t_philosophers	*vars;
}	t_philid;

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			init_vars(int argc, char **argv, t_philosophers *vars);
t_philid	*init_varsid(t_philosophers *vars);
void		gettime(t_philosophers *vars);
void		timepassed(t_philosophers *vars);
int			eating(t_philosophers *vars, t_philid *varsid);
int			sleeping(t_philosophers *vars, t_philid *varsid);
int			thinking(t_philosophers *vars, t_philid *varsid);
int			checkifdead(t_philosophers *vars, t_philid *varsid);
void		*cycle(t_philid *varsid);
void		take_forks(pthread_mutex_t *lfork, pthread_mutex_t *rfork);
void		free_forks(pthread_mutex_t *lfork, pthread_mutex_t *rfork);
int			checkinput(int argc, char **argv);
int			ft_strchr(const char *str, int c);
int			printstate(int what, t_philid *philid);

#endif
