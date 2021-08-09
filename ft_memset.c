/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 21:40:05 by bschende          #+#    #+#             */
/*   Updated: 2021/08/07 17:35:53 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *str, int c, size_t n)
{
	int		i;
	char	*temp;

	temp = ((char *)str);
	i = 0;
	while (*(temp + i))
	{
		if (i < (int)n)
		{
			*(temp + i) = c;
			i++;
		}
		else
			break ;
	}
	return (str);
}
