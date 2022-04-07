/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:00:08 by ben               #+#    #+#             */
/*   Updated: 2022/04/06 16:42:30 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	*arraya;
	int	*arrayb;

	i = 1;
	j = 0;
	arraya = malloc((argc - 1) * sizeof(int));
	arrayb = malloc((argc - 1) * sizeof(int));
	while (j < argc - 1)
	{
		arrayb[j] = ft_atoi(argv[i]);
		arraya[j] = arrayb[j];
		i++;
		j++;
	}
	operating(arraya, arrayb, (argc - 1));
	return (0);
}
//from here on push everything to other function, only include free at the end*/

void	operating(int *arraya, int *arrayb, int size)
{
	int	i;
	int	*sizea;
	int	*sizeb;

	i = 0;
	sizea = malloc(sizeof(int));
	sizeb = malloc(sizeof(int));
	*sizea = size;
	*sizeb = 0;
	bubblesort(arrayb, size);
	// while (i < size)
	// {
	// 	ft_printf("%i	%i\n", arrayb[i], arraya[i]);
	// 	i++;
	// }
	indexing(arraya, arrayb, size);
	// i = 0;
	// while (i < size)
	// {
	// 	ft_printf("%i	%i\n", arraya[i], arrayb[i]);
	// 	i++;
	// }
	cleararray(arrayb, size);
	i = 0;
	while (i < size)
	{
		ft_printf("%i	%i\n", arraya[i], arrayb[i]);
		i++;
	}
	i = chunks(sizea);
	ft_printf("%i\n", i);
	// swapa(arraya, sizea);
	// i = 0;
	// while (i < size)
	// {
	// 	ft_printf("%i	%i\n", arraya[i], arrayb[i]);
	// 	i++;
	// }
	// pushb(arraya, arrayb, sizea, sizeb);
	// i = 0;
	// while (i < size)
	// {
	// 	ft_printf("%i	%i	%i	%i\n", arraya[i], arrayb[i], *sizea, *sizeb);
	// 	i++;
	// }
	// pushb(arraya, arrayb, sizea, sizeb);
	// ft_printf("\n%i	%i\n",*sizea, *sizeb);
	// pushb(arraya, arrayb, sizea, sizeb);
	// pushb(arraya, arrayb, sizea, sizeb);
	// pushb(arraya, arrayb, sizea, sizeb);
	// pushb(arraya, arrayb, sizea, sizeb);
	// i = 0;
	// while (i < size)
	// {
	// 	ft_printf("%i	%i	%i	%i\n", arraya[i], arrayb[i], *sizea, *sizeb);
	// 	i++;
	// }
	// rotateb(arrayb, sizeb);
	// i = 0;
	// while (i < size)
	// {
	// 	ft_printf("%i	%i	%i	%i\n", arraya[i], arrayb[i], *sizea, *sizeb);
	// 	i++;
	// }
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
