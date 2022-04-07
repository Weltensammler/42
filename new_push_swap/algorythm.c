/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:06:23 by bschende          #+#    #+#             */
/*   Updated: 2022/04/07 20:25:06 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_pushswap *vars)
{
	int	chunk;
	int	i;
	

	
}

int	chunks(t_pushswap *vars)
{
	int	chunks;
	int	size;

	chunks = 0;
	size = vars->sizea;
	while (size > 2)
	{
		if ((size % 2) != 0)
			size = (size / 2) + 1;
		else
			size = size / 2;
		chunks++;
		printf("%i\n", size);
	}
	return (chunks);
}
