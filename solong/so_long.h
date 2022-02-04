/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:33:55 by bschende          #+#    #+#             */
/*   Updated: 2022/02/04 17:37:10 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_solong
{
	char	*path;
	char	*line;
	char	*string;
	char	**array;
	int		lines;
	int		col;
	int		fd;
	int		x;
	int		y;
	int		pl_x;
	int		pl_y;
	int		player_moves;
	int		ccount;
	void	*mlx;
	void	*win;
	void	*wa;
	void	*pl;
	void	*it;
	void	*fl;
	void	*ex;
}	t_solong;

void	ber_check(t_solong *vars);
int		countlines(t_solong *vars);
int		countcol(t_solong *vars);
void	validchar(t_solong *vars);
void	rectangle(t_solong *vars);
int		walledin(t_solong *vars);
void	check_min_objects(t_solong *vars);
void	check_min_it(t_solong *vars);
void	check_min_pl(t_solong *vars);
void	check_min_ex(t_solong *vars);
void	find_player(t_solong *vars);
void	get_map(t_solong *vars);
int		draw_map(t_solong *vars);
void	load_images(t_solong *vars);
void	load_img_wall(t_solong *vars);
void	load_img_player(t_solong *vars);
void	load_img_item(t_solong *vars);
void	load_img_floor(t_solong *vars);
void	load_img_exit(t_solong *vars);
void	endgame(t_solong *vars);
int		goodbye(t_solong *vars);
void	freemap(t_solong *vars);
void	imagefail1(t_solong *vars);
void	imagefail2(t_solong *vars);
void	imagefail3(t_solong *vars);
void	imagefail4(t_solong *vars);
void	imagefail5(t_solong *vars);
void	freedom(t_solong *vars);
void	wrong_format(t_solong *vars);
void	move_right(t_solong *vars);
void	move_up(t_solong *vars);
void	move_down(t_solong *vars);
void	move_left(t_solong *vars);

#endif
