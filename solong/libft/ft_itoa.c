/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 00:09:25 by bschende          #+#    #+#             */
/*   Updated: 2021/08/25 18:34:15 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	int			x;
	long int	num;
	char		*numbr1;

	num = n;
	x = ft_count(num);
	numbr1 = ft_calloc(1, ft_count(num) + 2);
	if (!numbr1)
		return (NULL);
	if (num < 0)
	{
		*numbr1 = '-';
		num = num * -1;
	}
	while (num >= 10)
	{
		*(numbr1 + x--) = (num % 10) + '0';
		num = num / 10;
	}
	*(numbr1 + x) = num + '0';
	return (numbr1);
}
