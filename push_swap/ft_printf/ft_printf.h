/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:35:39 by bschende          #+#    #+#             */
/*   Updated: 2022/02/18 12:37:17 by bschende         ###   ########.fr       */
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
int			ft_pitoa(int *p);
int			ft_uitoa(unsigned int *p);
int			dectohex_ptr(unsigned long n, int base, char *base_str);
int			print_ptr_addr(va_list ap);
int			dectohex(unsigned int n, int base, char *base_str);
int			wstr(va_list ap);
int			ft_pputchar_fd(char c, int fd);
void		*zeromem(void *str, size_t n);
void		*ft_pcalloc(size_t count, size_t size);

#endif
