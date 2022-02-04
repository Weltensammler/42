/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagefails.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 01:00:51 by bschende          #+#    #+#             */
/*   Updated: 2022/02/04 01:11:07 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	imagefail1(t_solong *vars)
{
	printf("Failed to load wall!");
	freemap(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	imagefail2(t_solong *vars)
{
	printf("Failed to load player!");
	freemap(vars);
	free(vars->wa);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	imagefail3(t_solong *vars)
{
	printf("Failed to load item!");
	freemap(vars);
	free(vars->wa);
	free(vars->pl);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	imagefail4(t_solong *vars)
{
	printf("Failed to load floor!");
	freemap(vars);
	free(vars->wa);
	free(vars->pl);
	free(vars->it);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	imagefail5(t_solong *vars)
{
	printf("Failed to load exit!");
	freemap(vars);
	free(vars->wa);
	free(vars->pl);
	free(vars->it);
	free(vars->fl);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
