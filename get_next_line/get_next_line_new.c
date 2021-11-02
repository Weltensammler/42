/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:18:59 by bschende          #+#    #+#             */
/*   Updated: 2021/10/26 18:48:12 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 42

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
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

// char	*ft_strjoin(char *left_str, char *buff)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!left_str)
// 	{
// 		left_str = (char *)malloc(1 * sizeof(char));
// 		left_str[0] = '\0';
// 	}
// 	if (!left_str || !buff)
// 		return (NULL);
// 	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (left_str)
// 		while (left_str[++i] != '\0')
// 			str[i] = left_str[i];
// 	while (buff[j] != '\0')
// 		str[i++] = buff[j++];
// 	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
// 	free(left_str);
// 	return (str);
// }

char	*join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	if (!s2 || !s1)
		return (NULL);
	i = 0;
	j = 0;
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (s1)
	{
		while (*(s1 + i))
		{
			*(str + i) = *(s1 + i);
			i++;
		}
	}
	while (*(s2 + j))
		*(str + i++) = *(s2 + j++);
	*(str + i) = '\0';
	free(s1);
	return (str);
}

char	*search(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s)
	{
		if (*(s + i) == c)
			return ((char *)(s + i));
		i++;
	}
	if (*(s + i) == c)
			return ((char *)(s + i));
	return (0);
}

char	*reading(char *s, int fd)
{
	char	*buffer;
	int		i;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!search(s, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		s = join(s, buffer);
	}
	free(buffer);
	return (s);
}

char	*line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (*(s + i) != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*(s + i) != '\n')
	{
		*(str + i) = *(s + i);
		i++;
	}
	if (*(str + i) == '\n')
		*(str + i++) = '\n';
	*(str + i) = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*savestring;
	char		*returnstring;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	savestring = reading(savestring, fd);
	if (!savestring)
		return (NULL);
	returnstring = line(savestring);
	// savestring = newstring(savestring);
	return (returnstring);
}

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("text.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if ((s = get_next_line(fd)))
	{
		printf("%s", s);
		printf("%i", fd);
	}
	if (!s)
			printf("OK");
	close(fd);
	return (0);
}
