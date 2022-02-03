/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:18:53 by bschende          #+#    #+#             */
/*   Updated: 2022/02/03 16:43:44 by bschende         ###   ########.fr       */
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
		imagefail();
}

void	load_img_player(t_solong *vars)
{
	int		img_w;
	int		img_h;

	vars->pl = mlx_xpm_file_to_image(vars->mlx, \
	"./images/character.xpm", &img_w, &img_h);
	if (!vars->pl)
		imagefail();
}

void	load_img_item(t_solong *vars)
{
	int		img_w;
	int		img_h;

	vars->it = mlx_xpm_file_to_image(vars->mlx, \
	"./images/item.xpm", &img_w, &img_h);
	if (!vars->it)
		imagefail();
}

void	load_img_floor(t_solong *vars)
{
	int		img_w;
	int		img_h;

	vars->fl = mlx_xpm_file_to_image(vars->mlx, \
	"./images/floor.xpm", &img_w, &img_h);
	if (!vars->fl)
		imagefail();
}

void	load_img_exit(t_solong *vars)
{
	int		img_w;
	int		img_h;

	vars->ex = mlx_xpm_file_to_image(vars->mlx, \
	"./images/exit.xpm", &img_w, &img_h);
	if (!vars->ex)
		imagefail();
}
