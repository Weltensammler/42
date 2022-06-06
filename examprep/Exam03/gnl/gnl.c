/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:36:55 by bschende          #+#    #+#             */
/*   Updated: 2022/06/06 15:29:10 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char *gnl(int fd)
{
	static char	*string1;
	char		*string2;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string1 = fillstring(fd, string1);
	if (!string1)
		return (NULL);
	string2 = output(string1);
	string1 = new_string(string1);
	return (string2);
}

char	*fillstring(int fd, char *string1)
{
	char	*buffer;
	int		i;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if(!buffer)
		return (NULL);
	i = 1;
	while(!ft_strchr(string1, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if(i == -1)
		{
			free(buffer);
			return (NULL);
		}
		*(buffer + i) = '\0';
		string1 = ft_strjoin(string1, buffer);
	}
	free(buffer);
	return (string1);
}

// char	*fillstring(int fd, char *string1)
// {
// 	char	*buffer;
// 	int		i;

// 	i = 1;
// 	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	while (!ft_strchr(string1, '\n') && i != 0)
// 	{
// 		i = read(fd, buffer, BUFFER_SIZE);
// 		if (i == -1)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		buffer[i] = '\0';
// 		string1 = ft_strjoin(string1, buffer);
// 	}
// 	free(buffer);
// 	return (string1);
// }

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

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		*(str1 + 0) = '\0';
	}
	new = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (str1[i])
	{
		new[i] = str1[i];
		i++;
	}
	while (str2[j])
		new[i++] = str2[j++];
	new[i] = '\0';
	free(str1);
	return (new);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*output(char *string1)
{
	char	*output;
	int		i;

	i = 0;
	if (!string1[i])
		return (NULL);
	while (string1[i] && string1[i] != '\n')
		i++;
	output = malloc((i + 2) *sizeof (char));
	if (!output)
		return (0);
	i = 0;
	while (string1[i] && string1[i] != '\n')
	{
		output[i] = string1[i];
		i++;
	}
	if (string1[i] == '\n')
	{
		output[i] = string1[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*new_string(char *string1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (string1[i] && string1[i] != '\n')
		i++;
	if(!string1)
	{
		free(string1);
		return (NULL);
	}
	str = malloc((ft_strlen(string1) - (i + 1)) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	while (string1[i])
		str[j++] = string1[i++];
	str[j] = '\0';
	free(string1);
	return (str); 
}

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("test.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	while ((s = gnl(fd)))
	{
		printf("%s", s);
	}
	close(fd);
	return (0);
}
