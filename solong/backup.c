/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:31:28 by bschende          #+#    #+#             */
/*   Updated: 2022/02/02 18:53:22 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int	closewin(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
		printf("%i\n", keycode);
	return (0);
}

void	createwindow(char **array, int lines, int col)
{
	t_vars	vars;
	void	*mlx;
	void	*mlx_win;
	void	*img_wall;
	void	*img_char;
	void	*img_item;
	void	*img_floor;
	void	*img_exit;
	char	*wall = "./images/wall.xpm";
	char	*player = "./images/character.xpm";
	char	*item = "./images/item.xpm";
	char	*floor = "./images/floor.xpm";
	char	*exit = "./images/exit.xpm";
	int		img_width;
	int		img_height;
	int		c;
	int		l;
	int		i;
	int		j;

	c = 100 * col;
	l = 100 * lines;
	i = 0;
	j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, c, l, "Hello world!");
	wall = mlx_xpm_file_to_image(mlx, wall, &img_width, &img_height);
	player = mlx_xpm_file_to_image(mlx, player, &img_width, &img_height);
	item = mlx_xpm_file_to_image(mlx, item, &img_width, &img_height);
	floor = mlx_xpm_file_to_image(mlx, floor, &img_width, &img_height);
	exit = mlx_xpm_file_to_image(mlx, exit, &img_width, &img_height);
	while (array[i])
	{
		while (array[i][j])
		{
			if (array[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, wall, j * 100, i *100);
			if (array[i][j] == '0')
				mlx_put_image_to_window(mlx, mlx_win, floor, j * 100, i *100);
			if (array[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, player, j * 100, i *100);
			if (array[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, item, j * 100, i *100);
			if (array[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, exit, j * 100, i *100);
			j++;
		}
		j = 0;
		i++;
	}
	vars.mlx = mlx;
	vars.win = mlx_win;
	mlx_key_hook(vars.win, closewin, &vars);
	mlx_loop(mlx);
}

int	get_map(t_solong *vars)
{
	vars->string = malloc(sizeof(char));
	while ((vars->line = get_next_line(vars->fd)))
		vars->string = ft_strjoin(vars->string, vars->line);
	vars->lines = countlines(vars->string);
	vars->col = countcol(vars->string);
	if (!validchar(vars->string))
		return (0);
	vars->array = ft_split(vars->string, '\n');
	if (!rectangle(vars->array))
		return (0);
	if (!walledin(vars->array, vars->lines, vars->col))
	{
		printf("ERROR map not walled in!");
		return (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_solong	vars;

	vars.fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	get_map(&vars);
	createwindow(vars.array, vars.lines, vars.col);
	free(&vars);
	return (0);
}