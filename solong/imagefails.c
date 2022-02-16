/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagefails.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 01:00:51 by bschende          #+#    #+#             */
/*   Updated: 2022/02/16 12:30:54 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_fail(t_solong *vars)
{
	printf("Failed to load image!");
	freemap(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
