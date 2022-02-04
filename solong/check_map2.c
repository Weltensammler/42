/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:40:46 by bschende          #+#    #+#             */
/*   Updated: 2022/02/04 17:38:35 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ber_check(t_solong *vars)
{
	int		i;

	i = 0;
	while (vars->path[i])
		i++;
	if (vars->path[--i] != 'r')
		wrong_format(vars);
	if (vars->path[--i] != 'e')
		wrong_format(vars);
	if (vars->path[--i] != 'b')
		wrong_format(vars);
	if (vars->path[--i] != '.')
		wrong_format(vars);
}

void	check_min_objects(t_solong *vars)
{
	check_min_it(vars);
	check_min_pl(vars);
	check_min_ex(vars);
}

void	check_min_it(t_solong *vars)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (vars->string[i])
	{
		if (vars->string[i] == 'C')
			c++;
		i++;
	}
	if (c < 1)
	{
		printf("Map has not enough items! (min 1)");
		freemap(vars);
		exit(0);
	}
}

void	check_min_pl(t_solong *vars)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (vars->string[i])
	{
		if (vars->string[i] == 'P')
			c++;
		i++;
	}
	if (c != 1)
	{
		printf("Map has not enough or to many players! (1)");
		freemap(vars);
		exit(0);
	}
}

void	check_min_ex(t_solong *vars)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (vars->string[i])
	{
		if (vars->string[i] == 'E')
			c++;
		i++;
	}
	if (c < 1)
	{
		printf("Map has not enough exits! (min 1)");
		freemap(vars);
		exit(0);
	}
}
