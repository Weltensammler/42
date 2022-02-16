/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:34:43 by bschende          #+#    #+#             */
/*   Updated: 2022/02/16 13:54:16 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_input(int keycode, t_solong *vars)
{
	if (keycode == 65307)
	{
		freedom(vars);
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
	return (0);
}

int	main(int argc, char **argv)
{
	t_solong	vars;
	int			i;

	i = 0;
	vars.path = argv[1];
	vars.player_moves = 0;
	ber_check(&vars);
	vars.fd = open(argv[1], O_RDONLY);
	get_map(&vars);
	close(vars.fd);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "so_long");
	find_player(&vars);
	load_images(&vars);
	draw_map(&vars);
	mlx_key_hook(vars.win, player_input, &vars);
	mlx_hook(vars.win, 17, (1L << 17), goodbye, &vars);
	mlx_hook(vars.win, 12, (1L << 15), draw_map, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
