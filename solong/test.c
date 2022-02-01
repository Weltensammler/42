/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:04:43 by bschende          #+#    #+#             */
/*   Updated: 2022/01/31 13:44:13 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				printf("ERROR map not walled in!");
				return (0);
			}
			j++;
		}
		while (i != lines)
		{
			if (array[i][0] != '1' || array[i][col - 1] != '1')
			{
				printf("ERROR map not walled in!");
				return (0);
			}
			i++;
		}
		i++;
	}
	return (1);
}

void	createwindow(t_solong *vars)
{
	vars->win->relative_path_wall = "./images/wall.xpm";
	vars->win->relative_path_char = "./images/character.xpm";
	vars->win->relative_path_item = "./images/item.xpm";
	vars->win->relative_path_floor = "./images/floor.xpm";
	vars->win->relative_path_exit = "./images/exit.xpm";
	vars->win->c = 100 * vars->col;
	vars->win->l = 100 * vars->lines;
	vars->win->x = 0;
	vars->win->y = 0;
	vars->win->i = 0;
	vars->win->j = 0;
	vars->win->mlx = mlx_init();
	vars->win->mlx_win = mlx_new_window(vars->win->mlx, vars->win->c, vars->win->l, "Hello world!");
	vars->win->img_wall = mlx_xpm_file_to_image(vars->win->mlx, vars->win->relative_path_wall, &vars->win->img_width, &vars->win->img_height);
	vars->win->img_char = mlx_xpm_file_to_image(vars->win->mlx, vars->win->relative_path_char, &vars->win->img_width, &vars->win->img_height);
	vars->win->img_item = mlx_xpm_file_to_image(vars->win->mlx, vars->win->relative_path_item, &vars->win->img_width, &vars->win->img_height);
	vars->win->img_floor = mlx_xpm_file_to_image(vars->win->mlx, vars->win->relative_path_floor, &vars->win->img_width, &vars->win->img_height);
	vars->win->img_exit = mlx_xpm_file_to_image(vars->win->mlx, vars->win->relative_path_exit, &vars->win->img_width, &vars->win->img_height);
	while (vars->array[vars->win->i])
	{
		while (vars->array[vars->win->i][vars->win->j])
		{
			if (vars->array[vars->win->i][vars->win->j] == '1')
				mlx_put_image_to_window(vars->win->mlx, vars->win->mlx_win, vars->win->img_wall, vars->win->x, vars->win->y);
			if (vars->array[vars->win->i][vars->win->j] == '0')
				mlx_put_image_to_window(vars->win->mlx, vars->win->mlx_win, vars->win->img_floor, vars->win->x, vars->win->y);
			if (vars->array[vars->win->i][vars->win->j] == 'P')
				mlx_put_image_to_window(vars->win->mlx, vars->win->mlx_win, vars->win->img_char, vars->win->x, vars->win->y);
			if (vars->array[vars->win->i][vars->win->j] == 'C')
				mlx_put_image_to_window(vars->win->mlx, vars->win->mlx_win, vars->win->img_item, vars->win->x, vars->win->y);
			if (vars->array[vars->win->i][vars->win->j] == 'E')
				mlx_put_image_to_window(vars->win->mlx, vars->win->mlx_win, vars->win->img_exit, vars->win->x, vars->win->y);
			vars->win->j++;
			vars->win->x += 100;
		}
		vars->win->y += 100;
		vars->win->x = 0;
		vars->win->j = 0;
		vars->win->i++;
	}
	mlx_loop(vars->win->mlx);
}

int	closewin(int keycode, t_solong *vars)
{
	mlx_destroy_window(vars->win->mlx, vars->win->mlx_win);
	printf("%i\n", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_solong	vars;

	// vars.steps = 0;
	// closewin(vars);

	vars.fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	vars.string = malloc(sizeof(char));
	while ((vars.line = get_next_line(vars.fd)))
		vars.string = ft_strjoin(vars.string, vars.line);
	vars.lines = countlines(vars.string);
	vars.col = countcol(vars.string);
	if (!validchar(vars.string))
		return (0);
	vars.array = ft_split(vars.string, '\n');
	if (!rectangle(vars.array))
		return (0);
	if (!walledin(vars.array, vars.lines, vars.col))
		return (0);
	createwindow(&vars);
	mlx_key_hook(vars.win->mlx_win, closewin, &vars);
	free(vars.string);
	return (0);
}
