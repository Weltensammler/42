/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:31 by bschende          #+#    #+#             */
/*   Updated: 2022/03/12 13:42:29 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

t_list	*ft_pushlstnew(int content, int index);
void	printlist(t_list *head);
void	sa(t_list **head);
void	bubblesort(int *array, int size);
void	indexing(int *arraya, int *arrayb, int size);
void	cleararray(int *array, int size);
void	swapa(int *array);
void	swapb(int *array);
void	pushb(int *arraya, int *arrayb, int size);

#endif
