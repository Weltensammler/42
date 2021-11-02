/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:28:28 by bschende          #+#    #+#             */
/*   Updated: 2021/10/08 12:40:49 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"*/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 42

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	if (!dest && !src)
		return (NULL);
	temp2 = (char *)dest;
	temp = (char *)src;
	while (i < (int)n)
	{
		*(temp2 + i) = *(temp + i);
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	if (!dest && !src)
		return (NULL);
	temp2 = (char *)dest;
	temp = (char *)src;
	if (dest > src)
	{
		i = (int)n;
		while (i > 0)
		{
			*(temp2 + (i - 1)) = *(temp + (i - 1));
			i--;
		}
	}
	else
		dest = ft_memcpy(temp2, temp, n);
	return (dest);
}

void	*ft_memset(void *str, int c, size_t n)
{
	int				i;
	unsigned char	*temp;

	temp = ((unsigned char *)str);
	i = 0;
	while (i < (int)n)
		temp[i++] = (unsigned char)c;
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(size * count);
	if (!p)
		return (0);
	ft_bzero(p, size * count);
	return (p);
}

char	*ft_strdup(const char *string)
{
	char	*new;

	new = ft_calloc(ft_strlen(string) + 1, sizeof (*string));
	if (!new)
		return (NULL);
	ft_memcpy(new, string, ft_strlen(string));
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		count;

	if (!s1)
		return (NULL);
	count = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = ft_calloc(count, sizeof (*s1));
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, ft_strlen(s1));
	ft_memcpy((new + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	return (new);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*line;
	char		*string;
	int			i;
	int			c;

	// first protect
	// second search string for new line, copy the string to newline and then move memory from right to left, then return line
	// third copy buffer to end of string
	// four 

	if (!fd || fd > 1024)
		return (NULL);
	i = 0;
	c = 0;
	if (!line)
	{
		read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		line = buffer;
	}
	// this part in own function
	while (*(line + i))
	{
		if (*(line + i) == '\n')
		{
			string = ft_calloc(i + 1, 1);
			ft_memcpy(string, line, i);
			c = i;
			i++;
			while (*(line + i))
			{
				(*(line + i - c - 1)) = (*(line + i));
				i++;
			}
			*(line + i) = '\0';
			return (string);
		}
			// create new string and memmove right to left (i++) return string
		if ((i + 1) % BUFFER_SIZE == 0) // not sure if it works
		{
			buffer[read(fd, buffer, BUFFER_SIZE) + 1] = '\0';
			line = ft_strjoin(line, buffer);
		}
		i++;
	}
	if (!line)
		return (NULL);
	return (line);
}

int	main(void)
{
	int		fd;
// 	int		i;
	char	*BUFFER;
// 	char	space[5];

	fd = open("text.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	while (get_next_line(fd))
	{
		BUFFER = get_next_line(fd);
		printf("%i\n", fd);
// 	i = read(fd, BUFFER,4);
// 	space[4] = '\0';
		printf("%s\n", BUFFER);
	}
	return (0);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	int		s;
// 	char	*BUFFER;
// 	char	space[30];
// 	char	space2[100];

// 	i = 0;
// 	s = 0;
// 	fd = open("text.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
// 	BUFFER = space;
// 	printf("%i", fd);
// 	read(fd, BUFFER,15);
// 	while (*(BUFFER + i))
// 	{
// 		if (*(BUFFER + i) == '\n') //then create string from s to i
// 		{
// 			while (s < i)
// 			{
// 				space2[s] = space[s];
// 				s++;
// 			}
// 			i++;
// 			s = i;
// 			space2[s - 1] = '\0';
// 		}
// 		i++;
// 	}
// 	printf("%s\n%c", space2, space2[s]);
// }
