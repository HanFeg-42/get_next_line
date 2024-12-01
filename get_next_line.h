/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:39:37 by hfegrach          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:15 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// # include <stdlib.h>
// # include <sys/types.h>
// # include <sys/uio.h>
// # include <unistd.h>

// char	*get_next_line(int fd);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strchr(const char *string, int searchedChar );

// void	ft_bzero(void *s, size_t n);
// void	*ft_calloc(size_t elementCount, size_t elementSize);

// size_t	ft_strlen(const char *theString);

#endif