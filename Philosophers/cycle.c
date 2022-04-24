/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:06:26 by bschende          #+#    #+#             */
/*   Updated: 2022/04/24 13:01:53 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*cycle(void *varsid)
{
	int			i;
	t_philid *	newid;

	i = 0;
	newid = varsid;
	while (!checkifdead(newid->vars, varsid) && i < newid->vars->notte)
	{
		eating(newid->vars, varsid);
		sleeping(newid->vars, varsid);
		thinking(newid->vars, varsid);
		i++;
	}
	return (NULL);
}