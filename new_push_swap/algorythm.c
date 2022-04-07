/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:06:23 by bschende          #+#    #+#             */
/*   Updated: 2022/04/06 17:16:36 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(int *arraya, int *arrayb, int *sizea, int *sizeb)
{
	int	chunk;
	int	i;
	

	
}

int	chunks(int *sizea)
{
	int	chunks;
	int	size;

	chunks = 0;
	size = *sizea;
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
