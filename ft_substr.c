/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:47:31 by bschende          #+#    #+#             */
/*   Updated: 2021/08/13 16:26:14 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (ft_strlen(s) <= start)
	{
		substr = ft_calloc(1, sizeof(char));
		return (substr);
	}
	substr = ft_calloc(len + 1, sizeof (*s));
	substr = ft_memcpy(substr, (s + start), len);
	return (substr);
}
