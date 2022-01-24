#include "./mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd)
{
	int		i;
	int		read_count;
	char	c;
	char	*line;

	i = 0;
	read_count = 0;
	while ((read_count = read(fd, &c, 1) > 0))
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
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path = "./images/wall.xpm";
	int		img_width;
	int		img_height;
	int		line;
	int		col;
	int		c;
	int		l;

	c = 1800;
	l = 1200;
	col = 0;
	line = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, c, l, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	while (line < l)
	{
		while (col < c)
		{
			if (line == 0 || line == l - 100)
			{
				mlx_put_image_to_window(mlx, mlx_win, img, col, line);
				col += 100;
			}
			else
			{
				mlx_put_image_to_window(mlx, mlx_win, img, col, line);
				col += c - 100;
			}
		}
		line += 100;
		col = 0;
	}
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		li;
	int		col;
	int		i;
	char	*line;

	i = 0;
	li = 1;
	col = 1;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
		while (line = get_next_line(fd))
		{
			while (i < ft_strlen(line))
			{
				if (line[i] != '1')
				{
					printf("WRONG MAP");
					exit;
				}
				i++;
		}
	}
}