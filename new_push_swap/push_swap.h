/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:31 by bschende          #+#    #+#             */
/*   Updated: 2022/04/17 23:17:52 by ben              ###   ########.fr       */
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
	int	*sta;
	int	*stb;
	int	size;
	int	sizea;
	int	sizeb;
	int	chunks;
	int	*chunksizes;
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
void	sortthreea(t_pushswap *vars);
void	sortthreeplusa(t_pushswap *vars);
void	sortfive(t_pushswap *vars);
int		findmid(int stack[], int size);
int		chunkinga(t_pushswap *vars);
int		counttopusha(int stack[], int mid, int size);
int		counttopushb(int stack[], int mid, int size);
int		checkifsortedplus(int stack[], int size);
int		chunkingplusb(int size, t_pushswap *vars);
int		algorythm(int size, t_pushswap *vars);
int		chunkingplusa(int size, t_pushswap *vars);
int		*createarray(int chunks);

#endif
