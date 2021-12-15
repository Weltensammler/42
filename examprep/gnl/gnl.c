#include "get_next_line.h"

char *get_next_line(int fd)
{
	int		read_count;
	int		i;
	char	c;
	char	*line;

	i = 0;
	read_count = 0;
	line = malloc(10000);
	while ((read_count = read(fd, &c, 1) > 0))
	{
		line[i++] = c;
		if (c == '\n')
			break;
	}
	if ((!read_count && !line[i - 1]) || read_count == -1)
	{
		free(line);
		return NULL;
	}
	line[i] = '\0';
	return (line);
}


char	*get_next_line(int fd)
{
	int		read_count;
	char	*buf;
	char	character;
	int		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(10000);
	read_count = read(fd, &character, 1);
	while (read_count > 0)
	{
		buf[i] = character;
		i++;
		if (c  == '\n')
			return(buf);
		read_count = read(fd, &character, 1);
	}
	if (read_count == -1)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}