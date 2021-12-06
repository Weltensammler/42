/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:23:47 by bschende          #+#    #+#             */
/*   Updated: 2021/12/03 18:16:21 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i))
	{
		if (*(str + i) == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *string1, char *string2)
{
	char	*str;
	int		i;
	int		j;

	if (!string1)
		string1 = malloc(1 * sizeof(char));
	if (!string1 || !string2)
		return (NULL);
	str = malloc(ft_strlen(string1) + ft_strlen(string2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (*(string1 + i))
	{
		*(str + i) = *(string1 + i);
		i++;
	}
	while (*(string2 + j))
		*(str + i++) = *(string2 + j++);
	*(str + i) = '\0';
	return (str);
}

char	*output(char *string1)
{
	int		i;
	char	*str;

	i = 0;
	if (!*(string1 + i))
		return (NULL);
	while (*(string1 + i) && *(string1 + i) != '\n')
		i++;
	str = malloc((i * sizeof(char)) + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (*(string1 + i) && *(string1 + i) != '\n')
	{
		*(str + i) = *(string1 + i);
		i++;
	}
	if (*(string1 + i) == '\n')
	{
		*(str + i) = *(string1 + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*new_string(char *string1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (*(string1 + i) && *(string1 + i) != '\n')
		i++;
	if (!string1)
	{
		free(string1);
		return (NULL);
	}
	str = malloc((ft_strlen(string1) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (*(string1 + i))
		*(str + j++) = *(string1 + i++);
	*(str + j) = '\0';
	free(string1);
	return (str);
}
