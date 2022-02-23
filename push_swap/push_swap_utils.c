/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:27:26 by bschende          #+#    #+#             */
/*   Updated: 2022/02/18 12:28:07 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_pushlstnew(int content, int index)
{
	t_list		*list_new;

	list_new = malloc(sizeof(t_list));
	if (list_new)
	{
		list_new->value = content;
		list_new->index = index;
		list_new->next = NULL;
	}
	return (list_new);
}

void	printlist(t_list *head)
{
	t_list	*temp = head;

	while (temp)
	{
		printf("%i	%i\n", temp->index, temp->value);
		temp = temp->next;
	}
}
