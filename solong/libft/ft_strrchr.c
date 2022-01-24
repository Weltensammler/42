/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:15:27 by bschende          #+#    #+#             */
/*   Updated: 2021/08/13 13:56:12 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	int				location;
	unsigned char	*temp;

	temp = ((unsigned char *)str);
	i = 0;
	location = -1;
	while (*(temp + i))
	{
		if (*(temp + i) == (char)c)
			location = i;
		i++;
	}
	if (*(temp + i) == (char)c)
		location = i;
	if (location == -1)
		return (NULL);
	return ((char *)temp + location);
}
