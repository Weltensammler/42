/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:28:30 by bschende          #+#    #+#             */
/*   Updated: 2022/02/01 16:17:53 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	countlines(char *string)
{
	int	i;
	int	lines;

	i = 0;
	lines = 1;
	while (string[i])
	{
		if (string[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

int	countcol(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

int	validchar(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (!ft_strchr("01CEP\n", string[i]))
		{
			printf("Map contains non valid characters! (01CEP)\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	rectangle(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strlen(array[0]) != ft_strlen(array[i]))
		{
			printf("ERROR, Map not rectangular!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	walledin(char **array, int lines, int col)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (array[i])
	{
		while (array[0][j])
		{
			if (!ft_strchr("1\n", array[0][j]))
				return (0);
			if (!ft_strchr("1\n", array[lines - 1][j]))
				return (0);
			j++;
		}
		while (i != lines)
		{
			if (array[i][0] != '1' || array[i][col - 1] != '1')
				return (0);
			i++;
		}
		i++;
	}
	return (1);
}
