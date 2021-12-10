/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:07:03 by bschende          #+#    #+#             */
/*   Updated: 2021/08/23 18:46:43 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	if (!dest && !src)
		return (NULL);
	temp2 = (char *)dest;
	temp = (char *)src;
	if (dest > src)
	{
		i = (int)n;
		while (i > 0)
		{
			*(temp2 + (i - 1)) = *(temp + (i - 1));
			i--;
		}
	}
	else
		dest = ft_memcpy(temp2, temp, n);
	return (dest);
}
