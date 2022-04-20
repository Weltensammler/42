/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 09:06:07 by ben               #+#    #+#             */
/*   Updated: 2022/04/18 17:51:08 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubblesort(t_pushswap *vars)
{
	int	a;
	int	b;
	int	temp;

	a = 0;
	b = 1;
	a = 0;
	while (b != 0)
	{
		b = 0;
		while (a < vars->size)
		{
			if (vars->stb[a] > vars->stb[a + 1] && a + 1 < vars->size)
			{
				temp = vars->stb[a + 1];
				vars->stb[a + 1] = vars->stb[a];
				vars->stb[a] = temp;
				b++;
			}
			a++;
		}
		a = 0;
	}
}

void	indexing(t_pushswap *vars)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < vars->size)
	{
		if (vars->sta[a] == vars->stb[b])
		{
			vars->sta[a] = b + 1;
			a++;
			b = 0;
		}
		else
			b++;
	}
}

void	cleararray(t_pushswap *vars)
{
	int	i;

	i = 0;
	while (i < vars->size)
		vars->stb[i++] = 0;
}

int	ft_isdigitps(int c, t_pushswap *vars)
{
	if (c > 47 && c < 58)
		return (1);
	free(vars->sta);
	free(vars->stb);
	write(1, "Error", 5);
	exit(0);
}

int	ft_atoips(const char *str, t_pushswap *vars)
{
	int	i;
	int	value;
	int	sign;

	i = 0;
	value = 0;
	sign = 1;
	while (*(str + i) == ' ' || (*(str + i) >= 9 && *(str + i) <= 13))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
		sign = 1 - 2 * (str[i++] == '-');
	else if (*str == '\0')
		return (0);
	while (ft_isdigitps(*(str + i), vars))
		value = value * 10 + *(str + i++) - '0';
	return ((int)(sign * value));
}
