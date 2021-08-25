/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:51:35 by bschende          #+#    #+#             */
/*   Updated: 2021/08/23 20:07:17 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	if (!dest && !src)
		return (NULL);
	temp2 = (char *)dest;
	temp = (char *)src;
	while (i < (int)n)
	{
		*(temp2 + i) = *(temp + i);
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	*(dest + size - 1) = '\0';
	if (ft_strlen(src) < size)
		ft_memcpy(dest, src, size - 1);
	else
		ft_memcpy(dest, src, ft_strlen(src));
	return (ft_strlen(dest));
}

size_t	ft_strlnewcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (*(src + i))
		{
			if (i == size)
			{
				i--;
				break ;
			}
			*(dest + i) = *(src + i);
			i++;
		}
	}
	*(dest + i) = '\0';
	while (*(src + i))
		i++;
	return (i);
}

void	test(int size)
{
	char	string[] = "Hello there, Venus";
	char	buffer[19];
	int		r;
	char	string1[] = "Hello there, Venus";
	char	buffer1[19];
	int		r1;

	r = strlcpy(buffer, string, size);
	printf("Copied '%s' into '%s', length %d\n", string, buffer, r);
	printf("ft\n");
	r1 = ft_strlnewcpy(buffer1, string1, size);
	printf("Copied '%s' into '%s', length %d\n", string1, buffer1, r1);
	printf("\n");
}

int	main(void)
{
	test(19);
	test(10);
	test(1);
	test(0);
	return (0);
}
