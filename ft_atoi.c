/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 13:39:09 by bschende          #+#    #+#             */
/*   Updated: 2021/08/25 04:56:39 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
