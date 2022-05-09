#include "philosophers.h"

int	checkinput(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
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

int	ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	*temp;

	temp = (unsigned char *)str;
	i = 0;
	while (*(temp + i))
	{
		if (*(temp + i) == (unsigned char)c)
			return (1);
		i++;
	}
	if (*(temp + i) == (unsigned char)c)
		return (1);
	return (0);
}

int	printstate(int what, t_philid *varsid)
{
	pthread_mutex_lock(&varsid->vars->death);
	// if (varsid->vars->todeath == 1)
	// {
	// 	printf("%li	%i	died\n", varsid->vars->runtime, varsid->ID);
	// 	return (0);
	// }
	if (what == 1)
		printf("%li	%i	has taken a fork\n", varsid->vars->runtime, varsid->ID);
	else if (what == 2)
		printf("%li	%i	is eating\n", varsid->vars->runtime, varsid->ID);
	else if (what == 3)
		printf("%li	%i	is sleeping\n", varsid->vars->runtime, varsid->ID);
	else if (what == 4)
		printf("%li	%i	is thinking\n", varsid->vars->runtime, varsid->ID);
	pthread_mutex_unlock(&varsid->vars->death);
	return (0);
}
