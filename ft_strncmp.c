/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:32:43 by bschende          #+#    #+#             */
/*   Updated: 2021/08/07 17:34:33 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n)
	{
		if (*(str1 + i) < *(str2 + i))
			return (-1);
		else if (*(str1 + i) > *(str2 + i))
			return (1);
		else if (i == (int)n && *(str1 + i) == *(str2 + i))
			return (0);
		else if (*(str1 + i) == '\0' && *(str2 + i) == '\0')
			break ;
		i++;
	}
	return (0);
}
