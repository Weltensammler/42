/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:34:43 by bschende          #+#    #+#             */
/*   Updated: 2022/02/02 21:46:46 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closewin(int keycode, t_solong *vars)
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

int	main(int argc, char **argv)
{
	t_solong	vars;

	vars.fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	get_map(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "so_long");
	printf("%s", vars.array[0]);
	load_images(&vars);
	draw_map(&vars);
	// mlx_key_hook(vars.win, playermove, &vars); //moving player /. exiting game / redraw map
	mlx_key_hook(vars.win, closewin, &vars);
	mlx_loop(vars.mlx);
	free(&vars);
	return (0);
}