/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 17:47:55 by bschende          #+#    #+#             */
/*   Updated: 2021/08/07 17:59:26 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int		i;
	char	*temp;
	char	*temp2;

	temp = ((char *)str1);
	temp2 = ((char *)str2);
	i = 0;
	while (i < (int)n)
	{
		if (*(temp + i) < *(temp2 + i))
			return (-1);
		else if (*(temp + i) > *(temp2 + i))
			return (1);
		else if (i == (int)n && *(temp + i) == *(temp2 + i))
			return (0);
		i++;
	}
	return (0);
}
