# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

int	countlines(char *string)
{
	int	i;
	int	lines;

	i = 0;
	lines = 1;
	while (string[i])
	{
		if (string[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

int	countcol(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

int	validchar(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (!ft_strchr("01CEP\n", string[i]))
		{
			printf("Map contains non valid characters! (01CEP)\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	rectangle(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strlen(array[0]) != ft_strlen(array[i]))
		{
			printf("ERROR, Map not rectangular!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	walledin(char **array, int lines, int col)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (array[i])
	{
		while (array[0][j])
		{
			if (!ft_strchr("1\n", array[0][j]) || !ft_strchr("1\n", array[lines - 1][j]))
			{
				printf("ERROR map not walled in!1");
				return (0);
			}
			j++;
		}
		while (i != lines)
		{
			if (array[i][0] != '1' || array[i][col - 1] != '1')
			{
				printf("ERROR map not walled in!2");
				return (0);
			}
			i++;
		}
		i++;
	}
	return (1);
}

void	createwindow(char **array, int lines, int col)
{
	void	*mlx;
	void	*mlx_win;
	void	*img_wall;
	void	*img_char;
	void	*img_item;
	void	*img_floor;
	void	*img_exit;
	char	*relative_path_wall = "./images/wall.xpm";
	char	*relative_path_char = "./images/character.xpm";
	char	*relative_path_item = "./images/item.xpm";
	char	*relative_path_floor = "./images/floor.xpm";
	char	*relative_path_exit = "./images/exit.xpm";
	int		img_width;
	int		img_height;
	int		y;
	int		x;
	int		c;
	int		l;
	int		i;
	int		j;

	c = 100 * col;
	l = 100 * lines;
	x = 0;
	y = 0;
	i = 0;
	j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, c, l, "Hello world!");
	img_wall = mlx_xpm_file_to_image(mlx, relative_path_wall, &img_width, &img_height);
	img_char = mlx_xpm_file_to_image(mlx, relative_path_char, &img_width, &img_height);
	img_item = mlx_xpm_file_to_image(mlx, relative_path_item, &img_width, &img_height);
	img_floor = mlx_xpm_file_to_image(mlx, relative_path_floor, &img_width, &img_height);
	img_exit = mlx_xpm_file_to_image(mlx, relative_path_exit, &img_width, &img_height);
	while (array[i])
	{
		while (array[i][j])
		{
			if (array[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, img_wall, x, y);
			if (array[i][j] == '0')
				mlx_put_image_to_window(mlx, mlx_win, img_floor, x, y);
			if (array[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, img_char, x, y);
			if (array[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, img_item, x, y);
			if (array[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, img_exit, x, y);
			j++;
			x += 100;
		}
		y += 100;
		x = 0;
		j = 0;
		i++;
	}
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	char	*line;
	char	*string;
	char	**array;
	int		lines;
	int		col;
	int		fd;

	col = 0;
	fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	string = malloc(sizeof(char));
	while ((line = get_next_line(fd)))
		string = ft_strjoin(string, line);
	lines = countlines(string);
	col = countcol(string);
	if (!validchar(string))
		return (0);
	array = ft_split(string, '\n');
	if (!rectangle(array))
		return (0);
	if (!walledin(array, lines, col))
		return (0);
	createwindow(array, lines, col);
	printf("%i\n%i", lines, col);
	free(string);
	return (0);
}
