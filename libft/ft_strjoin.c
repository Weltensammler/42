/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:26:35 by bschende          #+#    #+#             */
/*   Updated: 2021/08/23 18:18:04 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		count;

	if (!s1)
		return (NULL);
	count = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = ft_calloc(count, sizeof (*s1));
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, ft_strlen(s1));
	ft_memcpy((new + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	return (new);
}
