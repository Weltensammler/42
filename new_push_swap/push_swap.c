/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:00:08 by ben               #+#    #+#             */
/*   Updated: 2022/04/13 16:12:26 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	int			j;
	t_pushswap	vars;

	i = 1;
	j = 0;
	vars.chunks = 0;
	vars.sta = malloc((argc - 1) * sizeof(int));
	vars.stb = malloc((argc - 1) * sizeof(int));
	while (j < argc - 1)
	{
		vars.stb[j] = ft_atoi(argv[i]);
		vars.sta[j] = vars.stb[j];
		i++;
		j++;
	}
	vars.size = (argc - 1);
	operating(&vars);
	return (0);
}
//from here on push everything to other function, only include free at the end*/

void	operating(t_pushswap *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->sizea = vars->size;
	vars->sizeb = 0;
	bubblesort(vars);
	indexing(vars);
	cleararray(vars);
	i = 0;
	while (i < vars->size)
	{
		//ft_printf("%i	%i\n", vars->sta[i], vars->stb[i]);
		i++;
	}
	vars->chunks = chunks(vars);
	vars->chunksizes = malloc(vars->chunks * sizeof(int));
	i = 0;
	while (i < vars->chunks)
		vars->chunksizes[i++] = 0;
	//ft_printf("%i\n", i);
	while (vars->sizea > 3)
	{
		vars->chunksizes[j] = chunkinga(vars);
		j++;
		i = 0;
		// while (i < vars->size)
		// {
		// 	ft_printf("%i	%i	%i	%i\n", vars->sta[i], vars->stb[i], vars->sizea, vars->sizeb);
		// 	i++;
		// }
	}
	j = vars->chunks - 2;
	i = 0;
	while (j >= 0)
	{
		if (vars->sizea == 3)
			sortthreea(vars);
		if (!checkifsorteda(vars) && vars->sizea == 2)
			swapa(vars);
		while (vars->chunksizes[j] > 0)
		{
			if (checkifsortedplus(vars->stb, vars->chunksizes[j]))
			{
				while (i < vars->chunksizes[j])
				{
					pusha(vars);
					i++;
				}
				vars->chunksizes[j] = 0;
				j++;
			}
			if (vars->chunksizes[j] > 2)
			{
				vars->chunksizes[j] = vars->chunksizes[j] - chunkingplusb(vars->stb, vars->chunksizes[j], vars);
			}
			i = 0;
			while (i < vars->size)
			{
				ft_printf("%i	vara	%i	varb	%i	sizea	%i	sizeb (operating) %i j\n", vars->sta[i], vars->stb[i], vars->sizea, vars->sizeb, j);
				i++;
			}
			j--;
		}
	}
	//sortthreea(vars);
	// if (vars->sizea == 3)
	// 	sortthreea(vars);
	// if (vars->sizea == 5)
	// 	sortfive(vars);
	// rotateb(arrayb, sizeb);
	// pusha(arraya, arrayb, sizea, sizeb);
	// pusha(arraya, arrayb, sizea, sizeb);
	// pusha(arraya, arrayb, sizea, sizeb);
	// i = 0;
	// while (i < size)
	// {
	// 	ft_printf("%i	%i	%i	%i\n", arraya[i], arrayb[i], *sizea, *sizeb);
	// 	i++;
	// }
	// rotatea(arraya, sizea);
	// i = 0;
	// while (i < size)
	// {
	// 	ft_printf("%i	%i	%i	%i\n", arraya[i], arrayb[i], *sizea, *sizeb);
	// 	i++;
	// }
	// pusha(arraya, arrayb, sizea, sizeb);
	// rrotatea(arraya, sizea);
	// i = 0;
	// while (i < size)
	// {
	// 	ft_printf("%i	%i	%i	%i\n", arraya[i], arrayb[i], *sizea, *sizeb);
	// 	i++;
	// }
	// rrotateb(arrayb, sizeb);
	// i = 0;
	// while (i < size)
	// {
	// 	ft_printf("%i	%i	%i	%i\n", arraya[i], arrayb[i], *sizea, *sizeb);
	// 	i++;
	// }
	// pushb(arraya, arrayb, sizea, sizeb);
	// swapab(arraya, arrayb, sizea, sizeb);
	// i = 0;
	// while (i < size)
	// {
	// 	ft_printf("%i	%i	%i	%i\n", arraya[i], arrayb[i], *sizea, *sizeb);
	// 	i++;
	// }
	// rotateab(arraya, sizea, arrayb, sizeb);
	// i = 0;
	// while (i < size)
	// {
	// 	ft_printf("%i	%i	%i	%i\n", arraya[i], arrayb[i], *sizea, *sizeb);
	// 	i++;
	// }
}
