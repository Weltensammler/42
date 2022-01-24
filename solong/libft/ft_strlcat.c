/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:51:35 by bschende          #+#    #+#             */
/*   Updated: 2021/08/28 16:33:29 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dsize;

	dsize = ft_strlen(dest);
	if (dsize < size - 1 && size > 0)
		ft_strlcpy(&dest[dsize], src, size - dsize);
	if (dsize < size)
		return (dsize + ft_strlen(src));
	return (size + ft_strlen(src));
}
