#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	dectohex(unsigned int n, int base, char *base_str)
{
	static int	hexlen;
	int			index;

	hexlen = 0;
	if (n / base)
		dectohex(n / base, base, base_str);
	index = n % base;
	hexlen++;
	write(1, &base_str[index], 1);
	return (hexlen);
}

































int	wstr(va_list ap)
{
	int		i;
	char	*string;

	i = 0;
	string = va_arg(ap, char*);
	if (!string)
		string = "(null)";
	while (*(string + i))
		write(1, (string + i++), 1);
	return (i);
}

int	dectodec(int n, int base, char *base_str)
{
	int			index;
	static int	hexlen;
	int			i;

	hexlen = 0;
	i = 0;
	if (n < 0 && base == 10)
	{
		write(1, "-", 1);
		i++;
	}
	if (n / base)
	{
		if (n < 0)
			dectodec((n / base) * -1, base, base_str);
		else
			dectodec((n / base), base, base_str);
	}
	hexlen++;
	index = n % base;
	if (index < 0)
		index *= (-1);
	write(1, &base_str[index], 1);
	return (hexlen + i);
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

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(ap, fmt);
	while(*(fmt + i))
	{
		if (*(fmt + i) == '%')
		{
			i++;
			if (*(fmt + i) == 'd')
				j += dectodec(va_arg(ap, int), 10, "0123456789");
			if (*(fmt + i) == 'd')
				j += dectohex(va_arg(ap, int), 16, "0123456789abcdef");
			if (*(fmt + i) == 's')
				j += wstr(ap);
			i++;
		}
		if (*(fmt + i))
			j += write(1, (fmt + i++), 1);
	}
	va_end(ap);
	return (j);
}

int main()
{
	char *ch = "(a string)";
	int	i;


	i = ft_printf("%d %d %d %d %d", -2147483648, 17, 3, 1300, -400);
	ft_printf("\n");
	ft_printf("%d", i);
	ft_printf("\n");

	i = ft_printf("%x %x %x %x %x", 0, 40, -23, -2147483647, 7);
	ft_printf("\n");
	ft_printf("%d", i);
	ft_printf("\n");

	i = ft_printf("Hello this is %s in a string", ch);
	ft_printf("\n");
	ft_printf("%d", i);
	ft_printf("\n");

	i = ft_printf("Percentages: %%");
	ft_printf("\n");
	ft_printf("%d", i);
	ft_printf("\n");

	printf("\n");
	printf("\n");

	i = printf("%d %d %d %d %d", -2147483648, 17, 3, 1300, -400);
	printf("\n");
	printf("%d", i);
	printf("\n");

	i = printf("%x %x %x %x %x", 0, 40, -23, -2147483647, 7);
	printf("\n");
	printf("%d", i);
	printf("\n");

	i = printf("Hello this is %s in a string", ch);
	printf("\n");
	printf("%d", i);
	printf("\n");

	i = printf("Percentages: %%");
	printf("\n");
	printf("%d", i);
	printf("\n");

	return (0);
}
