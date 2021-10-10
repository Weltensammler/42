/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:30:34 by bschende          #+#    #+#             */
/*   Updated: 2021/10/10 16:01:28 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*search(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s)
	{
		if (*(s + i) == c)
			return (*(s + i));
		i++;
	}
	if (*(s + i) == c)
			return (*(s + i));
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	int		i;

	i = 0;
	p = malloc(count, size);
	if (!p)
		return (NULL);
	while (i < count)
	{
		*(p + i) = '\0';
		i++;
	}
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*(s1 + ++i))
		*(str + i) = *(s1 + i);
	while (*(s2 + j))
		*(str + i++) = *(s2 + j++)
	*(str + i) = '\0';
	free(s1);
	return (str)
}

char	*reading(char *s, int fd)
{
	char	*buffer;
	int		i;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char))
	i = 1;
	if (!buffer)
		return (NULL);
	while (!search(s, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		s = join(s, buffer);
		free(buffer);
		return (s);
	}
}

char	*get_next_line(int fd)
{
	static char	*savestring;
	char		*returnstring;

	if (fd > 1024 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	savestring = reading(savestring, fd);
	if (!savestring)
		return (NULL);
	returnstring = getline(savestring);
	savestring = newstring(savestring);
	return (returnstring);
}
