/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:32:04 by bschende          #+#    #+#             */
/*   Updated: 2021/08/11 13:43:01 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*new;

	new = ft_calloc(ft_strlen(string) + 1, sizeof (*string));
	ft_memcpy(new, string, ft_strlen(string));
	return (new);
}
