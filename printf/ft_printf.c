/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:45:29 by bschende          #+#    #+#             */
/*   Updated: 2021/10/17 23:39:52 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numconversion(void *p, char flag)
{
	int	i;

	i = 0;
	if (flag == 'i' || flag == 'd')
		i = ft_itoa(p);
	if (flag == 'u')
		i = ft_uitoa(p);
	if (flag == 'c')
		i = write(1, p, 1);
	if (flag == 'x')
		i = dectohex(*((int *)p), 16, "0123456789abcdef");
	if (flag == 'X')
		i = dectohex(*((int *)p), 16, "0123456789ABCDEF");
	return (i);
}

int	numbers(va_list ap, char flag)
{
	unsigned int	*value;
	int				j;

	j = 0;
	value = ft_calloc(1, sizeof(long int));
	*value = va_arg(ap, long int);
	j = numconversion(value, flag);
	free(value);
	return (j);
}

int	checkflag(const char *fmt, va_list ap)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (*(fmt + i))
	{
		if (*(fmt + i) == '%')
		{
			if (*(fmt + ++i) == 'i' || *(fmt + i) == 'd' || *(fmt + i) == 'c')
				j += numbers(ap, *(fmt + i));
			if (*(fmt + i) == 'u' || *(fmt + i) == 'x' || *(fmt + i) == 'X')
				j += numbers(ap, *(fmt + i));
			if (*(fmt + i) == 'p')
				j += print_ptr_addr(ap);
			if (*(fmt + i) == 's' && ap)
				j += wstr(ap);
			if (*(fmt + i) == '%')
				j += write(1, (fmt + i), 1);
			i++;
		}
		if (*(fmt + i) && *(fmt + i) != '%')
			j += write(1, (fmt + i++), 1);
	}
	return (j);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			char_count;

	char_count = 0;
	va_start(ap, fmt);
	char_count += checkflag(fmt, ap);
	va_end(ap);
	return (char_count);
}
