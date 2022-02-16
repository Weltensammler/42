/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagefails.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 01:00:51 by bschende          #+#    #+#             */
/*   Updated: 2022/02/16 16:23:37 by bschende         ###   ########.fr       */
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

void	mapformat(t_solong *vars)
{
	int	i;

	i = 0;
	while (vars->string[i])
		i++;
	if (vars->string[i - 1] == '\n')
	{
		printf("Map has wrong format!");
		free(vars->string);
		exit(0);
	}
}