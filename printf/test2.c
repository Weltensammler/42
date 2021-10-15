#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	pputchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

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

int	wchar(int*p)
{
	write(1, p, 1);
	return (1);
}

int	function(void *p, char flag)
{
	int	i;

	i = 0;
	if (flag == 'i' || flag == 'd')
		i = wint(p);
	if (flag == 'c')
		i = wchar(p);
	if (flag == 's')
		i = wstr(p);
	return (i);
}

int	numbers(va_list ap, char flag)
{
	unsigned int	*value;
	int				j;

	j = 0;
	value = ft_calloc(1, sizeof(unsigned int));
	*value = va_arg(ap, int);
	j = function(value, flag);
	free(value);
	return (j);
}

int	strings(va_list ap, char flag)
{
	char	*string;
	int		j;

	j = 0;
	string = va_arg(ap, char *);
	j = function(string, flag);
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
				j += numbers(ap, *(fmt + i));
			if (*(fmt + i) == 's')
				j += strings(ap, *(fmt + i));
			if (*(fmt + i) == '%')
				j += pputchar_fd('%', 1);
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
	int		tval;
	int		fg;
	int		org;
	int		my;
	char	c;
	char	*string = "wolf";

	c = 'A';
	tval = 703676500;
	fg = 95;
	org = printf("abcdeefhuewhfhwheiofhowheoifghoweh%iiofhoiwehf%doiuewqhgfew%dkrhgkuehwqrlkghkl%s\n", tval, fg, tval, string);
	my = ft_testf("%cabcdeefhuewhfhwheiofhowheoifghoweh%diofhoiwehf%doiuewqhgfew%dkrhgk%%uehwqrlkghkl%s\n", c, tval, fg, tval, string);
	printf("%i\n%i", org, my);
	return (0);
}
