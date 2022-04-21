/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:00:08 by ben               #+#    #+#             */
/*   Updated: 2022/04/21 18:21:43 by bschende         ###   ########.fr       */
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
			vars.stb[j] = ft_atoips(argv[i++], &vars);
			vars.sta[j] = vars.stb[j];
			j++;
	}
	vars.size = (argc - 1);
	operating(&vars);
	free(vars.sta);
	free(vars.stb);
	return (0);
}

void	operating(t_pushswap *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->sizea = vars->size;
	vars->sizeb = 0;
	checkdoubles(vars);
	if (!checkifsorteda(vars))
	{
		bubblesort(vars);
		indexing(vars);
		cleararray(vars);
		if (vars->size == 5)
			sortfive(vars);
		else if (vars->size == 3)
			sortthreea(vars);
		else
			algorythm(vars->sizea, vars);
	}
}

void	checkdoubles(t_pushswap *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->sizea)
	{
		j = 0;
		while (j < vars->sizea)
		{
			if (vars->sta[i] == vars->sta[j] && i != j)
			{
				free(vars->sta);
				free(vars->stb);
				write(1, "Error\n", 6);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	freedom(t_pushswap *vars)
{
	free(vars->sta);
	free(vars->stb);
	write(1, "Error\n", 6);
	exit(0);
}
