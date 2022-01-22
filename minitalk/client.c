/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 21:07:23 by bschende          #+#    #+#             */
/*   Updated: 2021/12/22 17:06:12 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

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

void	send_message(int pid, char *string)
{
	int		i;
	int		j;

	i = 0;
	while (*(string + i))
	{
		j = 0;
		while (j < 7)
		{
			if ((*(string + i) & 1) == 0)
				kill(pid, SIGUSR1);
			if ((*(string + i) & 1) == 1)
				kill(pid, SIGUSR2);
			*(string + i) = *(string + i) >> 1;
			j++;
			usleep(200);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Invalid Arguments!\n./client [PID] [STR]\n", 40);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
