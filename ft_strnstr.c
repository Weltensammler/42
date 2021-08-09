/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:09:31 by bschende          #+#    #+#             */
/*   Updated: 2021/08/08 13:35:53 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(needle);
	if (ft_strlen((const char *)needle) == 0)
		return ((char *)haystack);
	else
	{
		while (i < (int)len && *(haystack + i))
		{
			if (ft_memcmp((char *)haystack + i, (char *)needle, size))
				i++;
			else
				return ((char *)haystack + i);
		}
	}
	return (0);
}
