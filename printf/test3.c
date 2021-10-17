#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

void	*zeromem(void *str, size_t n)
{
	int				i;
	unsigned char	*temp;

	temp = ((unsigned char *)str);
	i = 0;
	while (i < (int)n)
		temp[i++] = '\0';
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(size * count);
	if (!p)
		return (0);
	zeromem(p, size * count);
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

int	dectohex_ptr(unsigned long n, int base, char *base_str)
{
	int			index;
	static int	hexlen_ptr;

	hexlen_ptr = 0;

	if (n/base)
		dectohex_ptr(n/base, base, base_str);
	hexlen_ptr++;
	index = n % base;
	write(1, &base_str[index], 1);
	return (hexlen_ptr);
}

int	print_ptr_addr(va_list ap)
{
	int				i;
	unsigned long	value;

	i = 2;
	value = va_arg(ap, unsigned long);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	i += dectohex_ptr((unsigned long)value, 16, "0123456789abcdef");
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

char	*ft_uitoa(unsigned int n)
{
	int			x;
	long int	num;
	char		*numbr1;

	num = n;
	x = ft_count(num);
	numbr1 = ft_calloc(1, ft_count(num) + 2);
	if (!numbr1)
		return (NULL);
	while (num >= 10)
	{
		*(numbr1 + x--) = (num % 10) + '0';
		num = num / 10;
	}
	*(numbr1 + x) = num + '0';
	return (numbr1);
}

int	wint(int *p)
{
	int		i;
	char	*c;

	i = 0;
	c = ft_itoa(*p);
	while (*(c + i))
		i += write(1, (c + i), 1);
	return (i);
}

int	wuint(unsigned int *p)
{
	int		i;
	char	*c;

	i = 0;
	c = ft_uitoa(*p);
	while (*(c + i))
		i += write(1, (c + i), 1);
	return (i);
}

int	wstr(va_list ap)
{
	int		i;
	char	*string;

	i = 0;
	string = va_arg(ap, char *);
	while (*(string + i))
		write(1, (string + i++), 1);
	return (i);
}

int	dectohex(unsigned int n, int base, char *base_str)
{
	int			index;
	static int	hexlen;

	hexlen = 0;
	if (n / base)
		dectohex(n / base, base, base_str);
	hexlen++;
	index = n % base;
	write(1, &base_str[index], 1);
	return (hexlen);
}

int	function(void *p, char flag)
{
	int	i;

	i = 0;
	if (flag == 'i' || flag == 'd')
		i = wint(p);
	if (flag == 'u')
		i = wuint(p);
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
	*value = va_arg(ap, int);
	j = function(value, flag);
	free(value);
	return (j);
}

int	ft_printf(const char *fmt, va_list ap)
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
			if (*(fmt + i) == 's')
				j += wstr(ap);
			if (*(fmt + i) == '%')
				j += ft_putchar_fd('%', 1);
			i++;
		}
		j += write(1, (fmt + i++), 1);
	}
	return (j);
}

int	ft_testf(const char *fmt, ...)
{
	va_list		ap;
	int			char_count;

	char_count = 0;
	va_start(ap, fmt);
	char_count += ft_printf(fmt, ap);
	va_end(ap);
	return (char_count);
}

int	main(void)
{
	unsigned int		tval;
	int					fg;
	int					org;
	int					my;
	char				c;
	char				*string = "wolf";
	int					toto;
	char				*ptr;

	toto = 2545;
	c = 'A';
	tval = 4294967295;
	fg = 95;
	ptr = string;
	org = printf("%cabcdeefhuewhfhwheiofhowheoifghoweh%uiofhoiwehf%doiuewqhgfew%ukrhgk%%uehwqrlkghkl%stutu%xav%pec\n", c, tval, fg, tval, string, toto, ptr);
	my = ft_testf("%cabcdeefhuewhfhwheiofhowheoifghoweh%uiofhoiwehf%doiuewqhgfew%ukrhgk%%uehwqrlkghkl%stutu%xav%pec\n", c, tval, fg, tval, string, toto, ptr);
	printf("%i\n%i", org, my);
	return (0);
}
