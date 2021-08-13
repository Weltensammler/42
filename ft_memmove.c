/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:07:03 by bschende          #+#    #+#             */
/*   Updated: 2021/08/11 11:07:19 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
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
	{
		while (i < (int)n)
		{
			*(temp2 + i) = *(temp + i);
			i++;
		}
	}
	return (dest);
}
