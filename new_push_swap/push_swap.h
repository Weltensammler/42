/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:31 by bschende          #+#    #+#             */
/*   Updated: 2022/03/17 12:45:09 by ben              ###   ########.fr       */
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
void	operating(int *arraya, int *arrayb, int size);
void	bubblesort(int *array, int size);
void	indexing(int *arraya, int *arrayb, int size);
void	cleararray(int *array, int size);
void	swapa(int *array);
void	swapb(int *array);
void	pushb(int *arraya, int *arrayb, int *sizea, int *sizeb);
void	pusha(int *arraya, int *arrayb, int *sizea, int *sizeb);
void	rotatea(int *arraya, int *sizea);
void	rotateb(int *arrayb, int *sizeb);
void	rrotatea(int *arraya, int *sizea);

#endif
