/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:31 by bschende          #+#    #+#             */
/*   Updated: 2022/04/07 19:28:06 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_pushswap
{
	int	*arraya;
	int	*arrayb;
	int	sizea;
	int	sizeb;
}	t_pushswap;

void	operating(int *arraya, int *arrayb, int size);
void	bubblesort(int *array, int size);
void	indexing(int *arraya, int *arrayb, int size);
void	cleararray(int *array, int size);
void	swapa(int *array, int *sizea);
void	swapb(int *array, int *sizeb);
void	pushb(int *arraya, int *arrayb, int *sizea, int *sizeb);
void	pusha(int *arraya, int *arrayb, int *sizea, int *sizeb);
void	rotatea(int *arraya, int *sizea);
void	rotateb(int *arrayb, int *sizeb);
void	rrotatea(int *arraya, int *sizea);
void	rrotateb(int *arrayb, int *sizeb);
void	swapab(int *arraya, int *arrayb, int *sizea, int *sizeb);
void	rotateab(int *arraya, int *sizea, int *arrayb, int *sizeb);
void	rrotateab(int *arraya, int *sizea, int *arrayb, int *sizeb);
int		chunks(int *sizea);

#endif
