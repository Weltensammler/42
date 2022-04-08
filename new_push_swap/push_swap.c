/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:00:08 by ben               #+#    #+#             */
/*   Updated: 2022/04/08 18:43:13 by bschende         ###   ########.fr       */
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
	vars.arraya = malloc((argc - 1) * sizeof(int));
	vars.arrayb = malloc((argc - 1) * sizeof(int));
	while (j < argc - 1)
	{
		vars.arrayb[j] = ft_atoi(argv[i]);
		vars.arraya[j] = vars.arrayb[j];
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

	i = 0;
	vars->sizea = vars->size;
	vars->sizeb = 0;
	bubblesort(vars);
	// while (i < size)
	// {
	// 	ft_printf("%i	%i\n", arrayb[i], arraya[i]);
	// 	i++;
	// }
	indexing(vars);
	// i = 0;
	// while (i < size)
	// {
	// 	ft_printf("%i	%i\n", arraya[i], arrayb[i]);
	// 	i++;
	// }
	cleararray(vars);
	i = 0;
	while (i < vars->size)
	{
		ft_printf("%i	%i\n", vars->arraya[i], vars->arrayb[i]);
		i++;
	}
	i = chunks(vars);
	// ft_printf("%i\n", i);
	sorting(vars);
	// rotateb(arrayb, sizeb);
	i = 0;
	while (i < vars->size)
	{
		ft_printf("%i	%i	%i	%i\n", vars->arraya[i], vars->arrayb[i], vars->sizea, vars->sizeb);
		i++;
	}
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
