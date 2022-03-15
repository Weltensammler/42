/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 17:47:55 by bschende          #+#    #+#             */
/*   Updated: 2021/08/24 15:48:36 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int				i;
	unsigned char	*temp;
	unsigned char	*temp2;

	temp = ((unsigned char *)str1);
	temp2 = ((unsigned char *)str2);
	i = 0;
	while (i < (int)n)
	{
		if (*(temp + i) < *(temp2 + i))
			return (*(temp + i) - *(temp2 + i));
		else if (*(temp + i) > *(temp2 + i))
			return (*(temp + i) - *(temp2 + i));
		else if (i == (int)n && *(temp + i) == *(temp2 + i))
			return (0);
		i++;
	}
	return (0);
}
