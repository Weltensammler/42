/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:31 by bschende          #+#    #+#             */
/*   Updated: 2022/04/08 12:10:41 by bschende         ###   ########.fr       */
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
	int	size;
	int	sizea;
	int	sizeb;
}	t_pushswap;

void	operating(t_pushswap *vars);
void	bubblesort(t_pushswap *vars);
void	indexing(t_pushswap *vars);
void	cleararray(t_pushswap *vars);
void	swapa(t_pushswap *vars);
void	swapb(t_pushswap *vars);
void	pushb(t_pushswap *vars);
void	pusha(t_pushswap *vars);
void	rotatea(t_pushswap *vars);
void	rotateb(t_pushswap *vars);
void	rrotatea(t_pushswap *vars);
void	rrotateb(t_pushswap *vars);
void	swapab(t_pushswap *vars);
void	rotateab(t_pushswap *vars);
void	rrotateab(t_pushswap *vars);
int		chunks(t_pushswap *vars);
int		checkifsorteda(t_pushswap *vars);
void	sorting(t_pushswap *vars);

#endif
