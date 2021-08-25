/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:51:35 by bschende          #+#    #+#             */
/*   Updated: 2021/08/24 15:36:48 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	i;
	int		dsize;

	count = (int)ft_strlen(dest);
	dsize = count;
	i = 0;
	if ((int)size - dsize - 1 > 0)
	{
		while (*(src + i))
		{
			if (i == size - dsize - 1)
				break ;
			else if ((int)size - (dsize - 1) < 0)
				break ;
			*(dest + count) = *(src + i);
			i++;
			count++;
			*(dest + count) = '\0';
		}
	}
	if (dsize < (int)size)
		return (dsize + ft_strlen(src));
	return ((int)size + ft_strlen(src));
}
