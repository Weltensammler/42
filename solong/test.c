# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

int	main(void)
{
	char	*line;
	char	*string;
	char	**array;
	int		i;
	int		j;
	int		lines;
	int		col;
	int		fd;

	i = 0;
	j = 0;
	col = 0;
	lines = 1;
	fd = open("text.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	string = malloc(sizeof(char));
	while ((line = get_next_line(fd)))
		string = ft_strjoin(string, line);
	// count how many lines
	while (string[i])
	{
		if (string[i] == '\n')
			lines++;
		i++;
	}
	i = 0;
	// count how many col
	while (string[i])
	{
		if (string[i] == '\n')
			break ;
		i++;
		col++;
	}
	i = 0;
	// check if only valid characters
	while (string[i])
	{
		if (ft_strchr("01CEP\n", string[i]))
			printf("Ok\n");
		else
			printf("not Ok\n");
		i++;
	}
	i = 0;
	array = ft_split(string, '\n');
	// check if rectangular
	while (array[i])
	{
		if (ft_strlen(array[0]) == ft_strlen(array[i]))
			printf("OK\n");
		if (ft_strlen(array[0]) != ft_strlen(array[i]))
			printf("ERROR, Map not rectangular!\n");
		i++;
	}
	i = 0;
	// check if walled in
	while (array[i])
	{
		while (array[0][j])
		{
			if (ft_strchr("1", array[i][j]))
				printf("OK");
			else
				printf("wrong MAP");
			j++;
		}
		printf("\n");
		i++;
		while (i != lines)
		{
			if (array[i][0] != '1' || array[i][col] != '1')
				printf("wrong MAP\n");
			else
				printf("Wall Ok\n");
			i++;
		}
		j = 0;
		while (array[lines - 1][j])
		{
			if (array[lines - 1][j] == '1')
				printf("OK");
			else
				printf("wrong MAP");
			j++;
		}
		i++;
	}
	printf("\n");
	i = 0;
	while (array[i])
		printf("%s\n", array[i++]);
	printf("%i\n%i", lines, col);
	free(string);
	return (0);
}
