/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:06:26 by bschende          #+#    #+#             */
/*   Updated: 2022/05/09 15:14:10 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*cycle(t_philid *varsid)
{
	int			i;

	i = 0;
	while (!checkifdead(varsid->vars, varsid) && i < varsid->vars->notte)
	{
		eating(varsid->vars, varsid);
		sleeping(varsid->vars, varsid);
		thinking(varsid->vars, varsid);
		i++;
		if (i == varsid->vars->notte)
			varsid->full = 1;
		// printf("cycle i %i notte %i\n", i, varsid->vars->notte);
		// i++;
	}
	return (NULL);
}
