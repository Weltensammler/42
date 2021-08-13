/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:32:43 by bschende          #+#    #+#             */
/*   Updated: 2021/08/13 11:32:04 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int				i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	i = 0;
	temp1 = (unsigned char *)str1;
	temp2 = (unsigned char *)str2;
	while (i < (int)n)
	{
		if (*(temp1 + i) < *(temp2 + i))
			return (-1);
		else if (*(temp1 + i) > *(temp2 + i))
			return (1);
		else if (i == (int)n && *(temp1 + i) == *(temp2 + i))
			return (0);
		else if (!*(temp1 + i) && !*(temp2 + i))
			break ;
		i++;
	}
	return (0);
}
