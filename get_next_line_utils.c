/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:39:23 by hfegrach          #+#    #+#             */
/*   Updated: 2024/12/01 13:29:42 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		sizetotal;
// 	char	*res;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	sizetotal = ft_strlen(s1) + ft_strlen(s2);
// 	res = malloc(sizeof(char) * (sizetotal + 1));
// 	if (!res || !s1 || !s2)
// 		return (NULL);
// 	while (s1[i] != 0)
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j] != 0)
// 	{
// 		res[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	res[sizetotal] = 0;
// 	return (res);
// }

// char	*ft_strchr(const char *string, int searchedChar )
// {
// 	char	*str;

// 	str = (char *)string;
// 	while (*str != searchedChar && *str != 0)
// 		str++;
// 	if (*str == searchedChar)
// 		return (str);
// 	else
// 		return (NULL);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	char	*str;
// 	size_t	i;

// 	str = (char *)s;
// 	i = 0;
// 	while (i < n)
// 	{
// 		str[i] = '\0';
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t elementCount, size_t elementSize)
// {
// 	char	*res;

// 	res = malloc(elementSize * elementCount);
// 	if (!res)
// 		return (NULL);
// 	ft_bzero(res, elementSize * elementCount);
// 	return (res);
// }

// size_t	ft_strlen(const char *theString)
// {
// 	int	i;

// 	i = 0;
// 	while (theString[i])
// 		i++;
// 	return (i);
// }

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ret = malloc(1);
		if (!ret)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;

	unsigned int (i), (j), (size);
	if (!s1 || !s2)
		return (NULL);
	size = (ft_strlen(s1) + ft_strlen(s2));
	join = (char *)malloc(sizeof(char) * size + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		join[i + j] = s2[j];
		j++;
	}
	join[size] = '\0';
	free(s1);
	s1 = NULL;
	return (join);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}