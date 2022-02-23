/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:57:54 by bschende          #+#    #+#             */
/*   Updated: 2022/02/20 16:30:24 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head)
{
	t_list	*temp1;
	t_list	*temp2;
	t_list	*temp3;

	temp1 = *head;
	temp1 = temp1->next;
	temp1 = temp1->next;
	temp2 = *head;
	temp2 = temp2->next;
	temp3 = *head;
	temp3->next = temp1;
	temp2->next = temp3;
	*head = temp2;
	ft_printf("sa\n");
}
