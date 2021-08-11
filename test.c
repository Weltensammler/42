/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:26:35 by bschende          #+#    #+#             */
/*   Updated: 2021/08/11 18:30:06 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	temp2 = (char *)dest;
	temp = (char *)src;
	while (i < (int)n)
	{
		*(temp2 + i) = *(temp + i);
		i++;
	}
	return (dest);
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

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *str, int c, size_t n)
{
	int		i;
	char	*temp;

	temp = ((char *)str);
	i = 0;
	while (*(temp + i))
	{
		if (i < (int)n)
		{
			*(temp + i) = c;
			i++;
		}
		else
			break ;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		count;

	count = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = ft_calloc(count, sizeof (*s1));
	ft_memcpy(new, s1, ft_strlen(s1));
	ft_memcpy((new + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	return (new);
}

char	*ft_strdup(const char *string)
{
	char	*new;

	new = ft_calloc(ft_strlen(string) + 1, sizeof (*string));
	ft_memcpy(new, string, ft_strlen(string));
	return (new);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	*(dest + size - 1) = '\0';
	ft_memcpy(dest, src, size - 1);
	return (ft_strlen(dest));
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int	destsize;
	
	destsize = ft_strlen(dest);
	ft_strlcpy((dest + (destsize)), src, size - destsize);
	destsize = ft_strlen(dest);
	*(dest + destsize) = '\0';
	return (ft_strlen(dest));
}

int		main(void)
{
	char	s1[12] = "mal ";
	char	s2[] = "schauen";

	ft_strlcat(s1, s2, 12);
	printf("%s|%s|", s2, s1);
	if (!*(s1 + 11))
		printf("TRUE %c", *(s1 + 11));
	return (0);
}
