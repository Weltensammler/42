/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:51:35 by bschende          #+#    #+#             */
/*   Updated: 2021/08/13 14:38:19 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	*(dest + size - 1) = '\0';
	if (ft_strlen(src) < size)
		ft_memcpy(dest, src, size - 1);
	else
		ft_memcpy(dest, src, ft_strlen(src));
	return (ft_strlen(dest));
}
