/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:32:43 by bschende          #+#    #+#             */
/*   Updated: 2021/08/30 13:30:37 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	i = 0;
	temp1 = (unsigned char *)str1;
	temp2 = (unsigned char *)str2;
	while (i < n)
	{
		if (*(temp1 + i) < *(temp2 + i))
			return ((*(temp1 + i)) - (*(temp2 + i)));
		else if (*(temp1 + i) > *(temp2 + i))
			return ((*(temp1 + i)) - (*(temp2 + i)));
		else if (i == n && *(temp1 + i) == *(temp2 + i))
			return ((*(temp1 + i)) - (*(temp2 + i)));
		else if (!*(temp1 + i) && !*(temp2 + i))
			break ;
		i++;
	}
	return (0);
}
