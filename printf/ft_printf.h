/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:35:39 by bschende          #+#    #+#             */
/*   Updated: 2021/10/17 23:41:21 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_printf(const char *format, ...);
int			checkflag(const char *fmt, va_list ap);
int			numbers(va_list ap, char flag);
int			numconversion(void *p, char flag);
int			ft_itoa(int *p);
int			ft_uitoa(unsigned int *p);
int			dectohex_ptr(unsigned long n, int base, char *base_str);
int			print_ptr_addr(va_list ap);
int			dectohex(unsigned int n, int base, char *base_str);
int			wstr(va_list ap);
int			ft_putchar_fd(char c, int fd);
void		*zeromem(void *str, size_t n);
void		*ft_calloc(size_t count, size_t size);

#endif
