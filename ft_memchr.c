/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:39:08 by bschende          #+#    #+#             */
/*   Updated: 2021/08/11 11:07:07 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	int		i;
	char	*temp;

	temp = ((char *)str);
	i = 0;
	while (i < (int)n)
	{
		if (temp[i] == c)
			return (temp + i);
		i++;
	}
	return (0);
}
