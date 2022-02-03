/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:34:43 by bschende          #+#    #+#             */
/*   Updated: 2022/02/03 21:10:18 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_input(int keycode, t_solong *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 100)
		move_right(vars);
	if (keycode == 119)
		move_up(vars);
	if (keycode == 115)
		move_down(vars);
	if (keycode == 97)
		move_left(vars);
	printf("%i\n", vars->player_moves);
	return (0);
}

int	main(int argc, char **argv)
{
	t_solong	vars;
	int			i;

	i = 0;
	vars.player_moves = 0;
	ber_check(argv[1]);
	vars.fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	get_map(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "so_long");
	find_player(&vars);
	load_images(&vars);
	draw_map(&vars);
	mlx_key_hook(vars.win, player_input, &vars);
	mlx_hook(vars.win, 17, (1L << 17), goodbye, "solong");
	mlx_hook(vars.win, 12, (1L << 15), draw_map, &vars);
	mlx_loop(vars.mlx);
	free(&vars);
	return (0);
}
