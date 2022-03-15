/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:00:08 by ben               #+#    #+#             */
/*   Updated: 2022/03/12 13:43:35 by ben              ###   ########.fr       */
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
//from here on push everything to other function, only include free at the end*/
	j = 0;
	bubblesort(arrayb, (argc - 1));
	while (j < argc - 1)
	{
		ft_printf("%i	%i\n", arrayb[j], arraya[j]);
		j++;
	}
	indexing(arraya, arrayb, (argc - 1));
	j = 0;
	while (j < argc - 1)
	{
		ft_printf("%i	%i\n", arraya[j], arrayb[j]);
		j++;
	}
	//cleararray(arrayb, (argc - 1));
	j = 0;
	while (j < argc - 1)
	{
		ft_printf("%i	%i\n", arraya[j], arrayb[j]);
		j++;
	}
	swapa(arraya);
	j = 0;
	while (j < argc - 1)
	{
		ft_printf("%i	%i\n", arraya[j], arrayb[j]);
		j++;
	}
	pushb(arraya, arrayb, (argc - 1));
	j = 0;
	while (j < argc - 1)
	{
		ft_printf("%i	%i\n", arraya[j], arrayb[j]);
		j++;
	}
	pushb(arraya, arrayb, (argc - 1));
	j = 0;
	while (j < argc - 1)
	{
		ft_printf("%i	%i\n", arraya[j], arrayb[j]);
		j++;
	}
	pushb(arraya, arrayb, (argc - 1));
	j = 0;
	while (j < argc - 1)
	{
		ft_printf("%i	%i\n", arraya[j], arrayb[j]);
		j++;
	}
	pushb(arraya, arrayb, (argc - 1));
	j = 0;
	while (j < argc - 1)
	{
		ft_printf("%i	%i\n", arraya[j], arrayb[j]);
		j++;
	}
	pushb(arraya, arrayb, (argc - 1));
	j = 0;
	while (j < argc - 1)
	{
		ft_printf("%i	%i\n", arraya[j], arrayb[j]);
		j++;
	}
}
