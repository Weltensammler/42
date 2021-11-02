/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:30:34 by bschende          #+#    #+#             */
/*   Updated: 2021/10/27 11:20:29 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 42

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_calloc(int count, int size)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(count * size);
	if (!p)
		return (NULL);
	while (i < count)
	{
		*(p + i) = '\0';
		i++;
	}
	return (p);
}

// char	*newstring(char *s)
// {
// 	int		i;
// 	int		j;
// 	char	*str;

// 	i = 0;
// 	while (*(s + i) && *(s + i) != '\n')
// 		i++;
// 	if (!s)
// 	{
// 		free(s);
// 		return (NULL);
// 	}
// 	str = ft_calloc(ft_strlen(s) - i + 1, sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	i++;
// 	j = 0;
// 	while (*(s + i))
// 		*(str + j++) = *(s + i++);
// 	*(str + j) = '\0';
// 	free(s);
// 	return (str);
// }

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

char	*line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	while (*(s + i) && *(s + i) != '\n')
		i++;
	str = malloc(i + 2 * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*(s + i) && *(s + i) != '\n')
	{
		*(str + i) = *(s + i);
		i++;
	}
	if (*(str + i) == '\n')
	{
		*(str + i) = '\n';
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
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

char	*join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	if (!s2 || !s1)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*reading(char *s, int fd)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(s, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		s = join(s, buffer);
	}
	free(buffer);
	return (s);
}

// char	*ft_read_to_left_str(int fd, char *left_str)
// {
// 	char	*buff;
// 	int		rd_bytes;

// 	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buff)
// 		return (NULL);
// 	rd_bytes = 1;
// 	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
// 	{
// 		rd_bytes = read(fd, buff, BUFFER_SIZE);
// 		if (rd_bytes == -1)
// 		{
// 			free(buff);
// 			return (NULL);
// 		}
// 		buff[rd_bytes] = '\0';
// 		left_str = ft_strjoin(left_str, buff);
// 	}
// 	free(buff);
// 	return (left_str);
// }

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
	savestring = ft_new_left_str(savestring);
	return (returnstring);
}

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("text.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		printf("%i", fd);
	}
	if (!s)
			printf("OK");
	close(fd);
	return (0);
}
