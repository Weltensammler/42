/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:45:26 by bschende          #+#    #+#             */
/*   Updated: 2021/10/17 23:50:01 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(long int n)
{
	int	i;

	i = 0;
	if (n < i)
	{
		i++;
		n = n * -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_itoa(int *p)
{
	int			x;
	long int	num;
	char		*numbr1;
	int			i;

	num = *p;
	i = -1;
	x = ft_count(num);
	numbr1 = ft_calloc(1, ft_count(num) + 2);
	if (!numbr1)
		return (0);
	if (num < 0)
		*numbr1 = '-';
	if (num < 0)
		num = num * -1;
	while (num >= 10)
	{
		*(numbr1 + x--) = (num % 10) + '0';
		num = num / 10;
	}
	*(numbr1 + x) = num + '0';
	while (*(numbr1 + ++i))
		write(1, (numbr1 + i), 1);
	free(numbr1);
	return (i);
}

int	ft_uitoa(unsigned int *p)
{
	int			x;
	long int	num;
	char		*numbr1;
	int			i;

	num = *p;
	i = 0;
	x = ft_count(num);
	numbr1 = ft_calloc(1, ft_count(num) + 2);
	if (!numbr1)
		return (0);
	while (num >= 10)
	{
		*(numbr1 + x--) = (num % 10) + '0';
		num = num / 10;
	}
	*(numbr1 + x) = num + '0';
	while (*(numbr1 + i))
	{
		write(1, (numbr1 + i), 1);
		i++;
	}
	free(numbr1);
	return (i);
}
