/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:15:27 by bschende          #+#    #+#             */
/*   Updated: 2021/08/07 18:14:39 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		location;
	char	*temp;

	temp = ((char *)str);
	i = 0;
	while (*(temp + i))
	{
		if (*(temp + i) == c)
			location = i;
		i++;
	}
	return (temp + location);
}
