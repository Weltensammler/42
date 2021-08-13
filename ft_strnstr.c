/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:09:31 by bschende          #+#    #+#             */
/*   Updated: 2021/08/13 12:30:26 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		size;

	i = 0;
	size = ft_strlen(needle);
	if (ft_strlen((const char *)needle) == 0)
		return ((char *)haystack);
	else
	{
		while (i < len && *(haystack + i))
		{
			if (ft_memcmp((char *)haystack + i, (char *)needle, size))
				i++;
			else if ((size + i - 1) > len)
				return (0);
			else
				return ((char *)haystack + i);
		}
	}
	return (0);
}
