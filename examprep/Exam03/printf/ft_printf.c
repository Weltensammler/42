#include <unistd.h>
#include <stdarg.h>

int ft_putnbr_base(long n, char *base, int base_len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -(n);
	}
	if (n == 0)
	{
		i += write(1, "0", 1);
		return (i);
	}
	if (n >= base_len)
	{
		i += ft_putnbr_base(n / base_len, base, base_len);
		i += write(1, &base[n % base_len], 1);
	}
	else if (n < base_len)
		i += write(1, &base[n], 1);
	return (i);
}

int	string(char *str)
{
	int		i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		j;
	va_list	ap;

	va_start(ap, fmt);
	i = 0;
	j = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == 'x')
				j += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", 16);
			if (fmt[i] == 'd')
				j += ft_putnbr_base(va_arg(ap, int), "0123456789", 10);
			if (fmt[i] == 's')
				j += string(va_arg(ap, char*));
			if (fmt[i] == '%')
				j += write(1, &fmt[i], 1);
			i++;
		}
		if (fmt[i])
			j += write(1, &fmt[i++], 1);
	}
	va_end(ap);
	return (j);
}

#include <stdio.h>

int main()
{
	char *ch = "(a string)";
	int i = 0;

	i = ft_printf("%d %d %d %d %d", -2147483647, 17, 3, 1300, -400);
	ft_printf("\n");
	printf("%d\n", i);

	i = printf("%d %d %d %d %d", -2147483647, 17, 3, 1300, -400);
	printf("\n");
	printf("%d\n", i);

	i = ft_printf("%x %x %x %x %x", 0, 40, -23, -2147483647, 7);
	ft_printf("\n");
	printf("%d\n", i);

	i = printf("%x %x %x %x %x", 0, 40, -23, -2147483647, 7);
	printf("\n");
	printf("%d\n", i);

	i = ft_printf("Hello this is %s in a string", ch);
	ft_printf("\n");
	printf("%d\n", i);

	i = printf("Hello this is %s in a string", ch);
	printf("\n");
	printf("%d\n", i);

	i = ft_printf("Percentages: %%");
	ft_printf("\n");
	printf("%d\n", i);

	i = printf("Percentages: %%");
	printf("\n");
	printf("%d\n", i);

	printf("\n");
	printf("\n");

	

	



	

	return (0);
}