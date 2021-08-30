/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:01:20 by bschende          #+#    #+#             */
/*   Updated: 2021/08/27 20:09:05 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
