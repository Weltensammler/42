#include <unistd.h>
#include <fcntl.h>

char	*ft_strjoin(char *str1, char *str2)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1)
	{	
		str1 = malloc(sizeof(char));
		if (!str1)
			return (NULL);
		str1 = '\0';
	}
	
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*fillstring(int fd)
{
	int		i;
	char	*buffer;

	i = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(string1, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		string1 = ft_strjoin(string1, buffer)
	}
	free (buffer);
	return (string1);
}

char	*gnl(int fd)
{
	static char	*string1;
	char		*string2;

	if (fd < 0)
		return (NULL);
	string1 = fillstring(fd);
	if (!string1)
		return (NULL);
	string2 = output(string1);
	string1 = new_string(string1);
	return (string2);
}