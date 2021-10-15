/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:14:31 by bschende          #+#    #+#             */
/*   Updated: 2021/10/15 00:39:58 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	int				i;
	unsigned char	*temp;

	temp = ((unsigned char *)str);
	i = 0;
	while (i < (int)n)
		temp[i++] = (unsigned char)c;
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(size * count);
	if (!p)
		return (0);
	ft_bzero(p, size * count);
	return (p);
}

static int	ft_count(long int n)
{
	int	i;

	i = 0;
	if (n < i)
	{
		i++;
		n = n * -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			x;
	long int	num;
	char		*numbr1;

	num = n;
	x = ft_count(num);
	numbr1 = ft_calloc(1, ft_count(num) + 2);
	if (!numbr1)
		return (NULL);
	if (num < 0)
	{
		*numbr1 = '-';
		num = num * -1;
	}
	while (num >= 10)
	{
		*(numbr1 + x--) = (num % 10) + '0';
		num = num / 10;
	}
	*(numbr1 + x) = num + '0';
	return (numbr1);
}

int	count(char *s)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (*(s + ++i))
		if (*(s + i) == '%')
			j++;
	return (j);
}

int	wint(int *p)
{
	int		i;
	char	*c;

	i = 0;
	c = ft_itoa(*p);
	while (*(c + i))
	{
		write(1, (c + i), 1);
		i++;
	}
	return (i);
}

int	wstr(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		write(1, (s + i++), 1);
	return (i);
}

int	function(void *p, char flag)
{
	int	i;

	i = 0;
	if (flag == 'i' || flag == 'd')
		i = wint(p);
	if (flag == 's')
		i = wstr(p);
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	int				i;
	int				j;
	unsigned int	*value;
	char			*p;
	va_list			ap;

	i = 0;
	j = 0;
	value = ft_calloc(1, sizeof(unsigned int));
	va_start(ap, fmt);
	while (*(fmt + i))
	{
		if (*(fmt + i) == '%')
		{
			i++;
			if (*(fmt + i) == 'i' || *(fmt + i) == 'd' || *(fmt + i) == 'c')
				*value = va_arg(ap, int);
			if (*(fmt + i) == 'u' || *(fmt + i) == 'x' || *(fmt + i) == 'X')
				*value = va_arg(ap, unsigned int);
			if (*(fmt + i) == 'p')
			{
				*value = va_arg(ap, unsigned long);
				j += function(value, *(fmt + i));
			}
			j += function(value, *(fmt + i));
			if (*(fmt + i++) == 's')
				p = va_arg(ap, char*);
			j += function(p, *(fmt + i));
		}
		j += write(1, (fmt + i++), 1);
	}
	return (j);
}

int main(void)
{
	int		tval;
	int		fg;
	int		org;
	int		my;
	char	c;
	char	*p = "wolf";

	c = 'A';
	tval = 703676500;
	fg = 95;
	org = printf("abcdeefhuewhfhwheiofhowheoifghoweh%iiofhoiwehf%doiuewqhgfew%ikrhgkuehwqr%slkghkl\n", tval, fg, tval, p);
	my = ft_printf("abcdeefhuewhfhwheiofhowheoifghoweh%iiofhoiwehf%doiuewqhgfew%ikrhgkuehwqr%slkghkl\n", tval, fg, tval, p);
	printf("%i\n%i", org, my);
	return (0);
}
