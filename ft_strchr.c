/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:39:36 by bschende          #+#    #+#             */
/*   Updated: 2021/07/28 14:08:34 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*temp;

	temp = ((char *)str);
	i = 0;
	while (temp[i])
	{
		if (temp[i] == c)
			return (temp + i);
		i++;
	}
	return (0);
}
