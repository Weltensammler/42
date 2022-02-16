/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:18:53 by bschende          #+#    #+#             */
/*   Updated: 2022/02/16 12:31:39 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img_wall(t_solong *vars)
{
	int		img_w;
	int		img_h;

	vars->wa = mlx_xpm_file_to_image(vars->mlx, \
	"./images/wall.xpm", &img_w, &img_h);
	if (!vars->wa)
		image_fail(vars);
}

void	load_img_player(t_solong *vars)
{
	int		img_w;
	int		img_h;

	vars->pl = mlx_xpm_file_to_image(vars->mlx, \
	"./images/character.xpm", &img_w, &img_h);
	if (!vars->pl)
		image_fail(vars);
}

void	load_img_item(t_solong *vars)
{
	int		img_w;
	int		img_h;

	vars->it = mlx_xpm_file_to_image(vars->mlx, \
	"./images/item.xpm", &img_w, &img_h);
	if (!vars->it)
		image_fail(vars);
}

void	load_img_floor(t_solong *vars)
{
	int		img_w;
	int		img_h;

	vars->fl = mlx_xpm_file_to_image(vars->mlx, \
	"./images/floor.xpm", &img_w, &img_h);
	if (!vars->fl)
		image_fail(vars);
}

void	load_img_exit(t_solong *vars)
{
	int		img_w;
	int		img_h;

	vars->ex = mlx_xpm_file_to_image(vars->mlx, \
	"./images/exit.xpm", &img_w, &img_h);
	if (!vars->ex)
		image_fail(vars);
}
