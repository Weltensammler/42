/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:28:30 by bschende          #+#    #+#             */
/*   Updated: 2022/02/16 14:24:07 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	countlines(t_solong *vars)
{
	int	i;
	int	lines;

	i = 0;
	lines = 1;
	while (vars->string[i])
	{
		if (vars->string[i] == '\n' && vars->string[i + 1])
			lines++;
		i++;
	}
	return (lines);
}

int	countcol(t_solong *vars)
{
	int	i;

	i = 0;
	while (vars->string[i])
	{
		if (vars->string[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

void	validchar(t_solong *vars)
{
	int	i;

	i = 0;
	while (vars->string[i])
	{
		if (!ft_strchr("01CEP\n", vars->string[i]))
		{
			printf("Map contains non valid characters! (01CEP)\n");
			free(vars->string);
			free(vars->line);
			exit(0);
		}
		i++;
	}
}

void	rectangle(t_solong *vars)
{
	int	i;

	i = 0;
	while (vars->array[i])
	{
		if (ft_strlen(vars->array[0]) != ft_strlen(vars->array[i]))
		{
			printf("ERROR, Map not rectangular!\n");
			freemap(vars);
			exit(0);
		}
		i++;
	}
}

int	walledin(t_solong *vars)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = vars->col;
	while (vars->array[i])
	{
		while (vars->array[0][j])
		{
			if (!ft_strchr("1\n", vars->array[0][j]))
				return (0);
			if (!ft_strchr("1\n", vars->array[vars->lines - 1][j]))
				return (0);
			j++;
		}
		while (++i != vars->lines)
		{
			if (vars->array[i][0] != '1' || vars->array[i][c - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}
