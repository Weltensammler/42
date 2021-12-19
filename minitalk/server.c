/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 21:07:32 by bschende          #+#    #+#             */
/*   Updated: 2021/12/19 23:57:08 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[11];
	int		i;
	char	mop;

	i = 0;
	mop = '+';
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n == -2147483648)
		return ;
	if (n < 0)
	{
		mop = '-';
		n = n * -1;
	}
	while (n >= 10)
	{
		arr[i++] = (n % 10) + '0';
		n = n / 10;
	}
	arr[i] = n + '0';
	if (mop == '-')
		write(fd, &mop, 1);
	while (i >= 0)
		write(fd, &arr[i--], 1);
}

void	receive(int sig)
{
	static unsigned char	k = '\0';
	static int				i = 0;

	if (sig == SIGUSR1)
		i++;
	if (sig == SIGUSR2)
	{
		if (i != 7)
			k += 1 << i;
		i++;
	}
	if (i == 7)
	{
		write(1, &k, 1);
		i = 0;
		k = '\0';
	}
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while (1)
		pause();
	return (0);
}
