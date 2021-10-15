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


int	myprintf(const char *fmt, ...)
{
	int		i;
	int		j;
	int		ret;
	int		save;
	int		value;
	char	valuec;
	char	*test;
	char	*testc;
	char	*tests;
	va_list	ap;

	va_start(ap, fmt);
	i = 0;
	save = 0;
	ret = 0;
	while (*(fmt + i))
	{
		if (*(fmt + i) == '%')
		{
			i++;
			if (*(fmt + i) == 'i' || *(fmt + i) == 'd')
			{
				j = 0;
				value = va_arg(ap, int);
				test = ft_itoa(value);
				while (*(test + j))
				{
					write(1, (test + j), 1);
					j++;
					ret++;
				}
				i++;
			}
			if (*(fmt + i) == 'c')
			{
				j = 0;
				valuec = va_arg(ap, int);
				testc = &valuec;
				write(1, testc, 1);
				i++;
			}
			if (*(fmt + i) == 's')
			{
				j = 0;
				tests = va_arg(ap, char*);
				while (*(tests + j))
				{
					write(1, (tests + j), 1);
					j++;
					ret++;
				}
				i++;
				ret++;
			}
		}
		write(1, (fmt + i), 1);
		i++;
		save++;
	}
	ret = save + ret;
	return (ret);
}

int main(void)
{
	int		tval;
	int		fg;
	int		org;
	int		my;
	char	c;
	char	string[] = "wolf";

	c = 'A';
	tval = 703676500;
	fg = 95;
	org = printf("abcdeefhuewhfhwheiofhowheoifghoweh%iiofhoiwehf%doiuewqhgfew%ikrhgku%cehwq%srlkghkl\n", tval, fg, tval, c, string);
	my = myprintf("abcdeefhuewhfhwheiofhowheoifghoweh%iiofhoiwehf%doiuewqhgfew%ikrhgku%cehwq%srlkghkl\n", tval, fg, tval, c, string);
	printf("%i\n%i", org, my);
	return (0);
}