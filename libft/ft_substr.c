/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:47:31 by bschende          #+#    #+#             */
/*   Updated: 2021/08/24 10:27:36 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		substr = ft_calloc(1, sizeof(char));
		if (!substr)
			return (NULL);
		return (substr);
	}
	substr = ft_calloc(len + 1, sizeof (*s));
	if (!substr)
		return (NULL);
	substr = ft_memcpy(substr, (s + start), len);
	return (substr);
}
