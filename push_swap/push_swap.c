/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:28:42 by bschende          #+#    #+#             */
/*   Updated: 2022/02/18 14:37:03 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*heada;
	int		i;

	i = 1;
	stacka = ft_pushlstnew(ft_atoi(argv[i]), i);
	i++;
	heada = stacka;
	while (argc > i)
	{
		stacka = ft_pushlstnew(ft_atoi(argv[i]), i);
		ft_lstadd_back(&heada, stacka);
		i++;
	}
	printlist(heada);
	sa(&heada);
	printlist(heada);
	return (0);
}
