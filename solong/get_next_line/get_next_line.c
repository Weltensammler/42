/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:39:17 by bschende          #+#    #+#             */
/*   Updated: 2022/01/24 14:09:57 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 42

char	*fillstring(int fd, char *string1)
{
	char	*buffer;
	int		i;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_gnlstrchr(string1, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		*(buffer + i) = '\0';
		string1 = ft_gnlstrjoin(string1, buffer);
	}
	free(buffer);
	return (string1);
}

char	*get_next_line(int fd)
{
	static char	*string1;
	char		*string2;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	string1 = fillstring(fd, string1);
	if (!string1)
		return (NULL);
	string2 = output(string1);
	string1 = new_string(string1);
	return (string2);
}
