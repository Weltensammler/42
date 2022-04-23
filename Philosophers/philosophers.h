/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:51:15 by bschende          #+#    #+#             */
/*   Updated: 2022/04/23 22:19:05 by bschende         ###   ########.fr       */
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

#endif
