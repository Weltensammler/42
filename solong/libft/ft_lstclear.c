/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:15:45 by bschende          #+#    #+#             */
/*   Updated: 2021/09/12 16:38:41 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (!lst)
		return ;
	ptr1 = *lst;
	while (ptr1->next)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
		del(ptr2->content);
		free(ptr2);
	}
	del(ptr1->content);
	free(ptr1);
	*lst = NULL;
}
