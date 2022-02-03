/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:40:46 by bschende          #+#    #+#             */
/*   Updated: 2022/02/03 20:31:25 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ber_check(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
		i++;
	if (arg[--i] != 'r')
		wrong_format();
	if (arg[--i] != 'e')
		wrong_format();
	if (arg[--i] != 'b')
		wrong_format();
	if (arg[--i] != '.')
		wrong_format();
}

void	check_min_objects(char *string)
{
	check_min_it(string);
	check_min_pl(string);
	check_min_ex(string);
}

void	check_min_it(char *string)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (string[i])
	{
		if (string[i] == 'C')
			c++;
		i++;
	}
	if (c < 1)
	{
		printf("Map has not enough items! (min 1)");
		exit(0);
	}
}

void	check_min_pl(char *string)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (string[i])
	{
		if (string[i] == 'P')
			c++;
		i++;
	}
	if (c != 1)
	{
		printf("Map has not enough or to many players! (1)");
		exit(0);
	}
}

void	check_min_ex(char *string)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (string[i])
	{
		if (string[i] == 'E')
			c++;
		i++;
	}
	if (c < 1)
	{
		printf("Map has not enough exits! (min 1)");
		exit(0);
	}
}
