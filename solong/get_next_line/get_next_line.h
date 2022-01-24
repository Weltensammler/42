/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:25:42 by bschende          #+#    #+#             */
/*   Updated: 2022/01/24 14:08:31 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*fillstring(int fd, char *string1);
size_t	ft_gnlstrlen(char *str);
char	*ft_gnlstrchr(char *str, int c);
char	*ft_gnlstrjoin(char *string1, char *string2);
char	*output(char *string1);
char	*new_string(char *string1);

#endif
