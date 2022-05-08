/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:51:45 by bschende          #+#    #+#             */
/*   Updated: 2022/05/02 11:27:20 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
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
	while (ft_isdigit(*(str + i)))
		value = value * 10 + *(str + i++) - '0';
	return ((int)(sign * value));
}

int	main(int argc, char **argv)
{
	int	array[3];

	array[0] = ft_atoi(argv[1]);
	array[1] = ft_atoi(argv[2]);
	array[2] = ft_atoi(argv[3]);
	printf("%i, %i, %i, %i\n", argc, array[0], array[1], array[2]);
}
