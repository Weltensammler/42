/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:39:36 by bschende          #+#    #+#             */
/*   Updated: 2022/02/16 13:33:01 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	*temp;

	temp = (unsigned char *)str;
	i = 0;
	while (*(temp + i))
	{
		if (*(temp + i) == (unsigned char)c)
			return ((char *)(temp + i));
		i++;
	}
	if (*(temp + i) == (unsigned char)c)
		return ((char *)(temp + i));
	return (NULL);
}
