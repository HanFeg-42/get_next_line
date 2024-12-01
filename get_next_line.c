/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:39:28 by hfegrach          #+#    #+#             */
/*   Updated: 2024/12/01 16:33:49 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//==============================code 3chwa2i======================================


/*========================bghit ghi ntester wahed l3iba=======================*/
//--------------------------------it worked wakha sghrtha-----------------------------------//

// void	fill_in_save(int fd, ssize_t *rd, char **save, char **buff)
// {
// 	while (1)
// 	{
// 		*rd = read(fd, *buff, BUFFER_SIZE);
// 		if (*rd == 0 || *rd == -1)
// 			break ;
// 		(*buff)[*rd] = '\0';
// 		if (!(*save))
// 			*save = ft_strdup(*buff);
// 		else
// 			*save = ft_strjoin(*save, *buff);
// 		if (ft_strchr(*save, '\n'))
// 			break ;
// 	}
// }

// char	*read_line(char **save, ssize_t rd)
// {
// 	char	*line;
// 	char	*new;
// 	char	*nl_ptr ;

// 	nl_ptr = ft_strchr(*save, '\n') ;
// 	if (nl_ptr && rd)
// 	{
// 		line = ft_substr(*save, 0, nl_ptr - *save + 1) ;
// 		new = ft_strdup(nl_ptr + 1) ;
// 		free(*save);
// 		*save = ft_strdup(new);
// 		return (free(new), line);
// 	}
// 	else if (!rd)
// 		return (new = ft_strdup(*save), free(*save), *save = NULL, new);
// 	return (NULL);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*save;
// 	char		*buff;
// 	ssize_t		rd;

// 	buff = NULL ;
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	buff = malloc((BUFFER_SIZE * sizeof(char)) + 1);
// 	if (!buff)
// 		return (NULL);
// 	fill_in_save(fd, &rd, &save, &buff);
// 	free(buff);
// 	if (!save)
//     	return (NULL) ;
// 	return (read_line(&save, rd));
// }

/*========================YARBI TKOUN THE LAST TRY=======================*/
// ------------------it works --------------------------do not touch it----

void	fill_in_save(int fd, ssize_t *rd, char **save, char **buff)
{
	while (1)
	{
		*rd = read(fd, *buff, BUFFER_SIZE);
		if (*rd == 0 || *rd == -1)
			break ;
		(*buff)[*rd] = '\0';
		if (!(*save))
			*save = ft_strdup(*buff);
		else
			*save = ft_strjoin(*save, *buff);
		if (!(*save))
			break ;
		if (ft_strchr(*save, '\n'))
			break ;
	}
}

char	*test(char **save)
{
	char	*tmp;

	tmp = ft_strdup(*save);
	if (!tmp || !tmp[0])
		return (free(*save), free(tmp),*save = NULL, NULL);
	return (free(*save), *save = NULL, tmp);
}

char	*read_line(char **save)
{
	char	*line;
	char	*new;

	line = ft_substr(*save, 0, ft_strchr(*save, '\n') - *save + 1);
	if (!line)
		return (free(line), line = NULL, NULL);
	new = ft_strdup(ft_strchr(*save, '\n') + 1);
	if (!new)
		return (free(*save), free(line), *save = NULL, NULL);
	free(*save);
	*save = ft_strdup(new);
	if (!(*save))
		return (free(new), free(line), *save = NULL, NULL);
	return (free(new), line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buff;
	ssize_t		rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// if (save && save[0] == '\0')
	// 	return (free(save), NULL);
	buff = malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!buff)
		return (NULL);
	fill_in_save(fd, &rd, &save, &buff);
	free(buff);
	if (save != NULL && ft_strchr(save, '\n'))
		return (read_line(&save));
	else if (!rd && save != NULL)
		return (test(&save));
	return (NULL);
}

