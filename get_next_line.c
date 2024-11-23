/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:39:28 by hfegrach          #+#    #+#             */
/*   Updated: 2024/11/23 14:58:39 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(char *s)
{
    int len;
    char *ret;
    int i;

    len = 0;
    while(s[len] != '\n')
        len++;
    ret = malloc(len + 2);
    i = 0;
    while(s[i] != '\n')
        ret[i] = s[i++];
    ret[i++] = '\n';
    ret[i] = '\0';
    return (ret);
}

char *get_next_line(int fd)
{
    char *str;
    char *line;
    
    if (fd == -1)
        return NULL;
    str = malloc(BUFFER_SIZE + 1);
    if (read(fd, str, BUFFER_SIZE) != -1)
        printf("%s\n", str);
    line = read_line(str);
    str = ft_strchr(str, '\n') + 1;
    return line;
}

int main()
{
    int fd = open("file.txt", O_CREAT | O_RDONLY, 0640);
    if (fd == -1)
        return 2;
    char *s = get_next_line(fd);
    printf("%s\n", s);
    return (0);
}

// int main()
// {
//     char *str = malloc(10);
//     int fd = open("file.txt", O_CREAT | O_RDONLY, 0640);
//     if (fd == -1)
//         return 2;
//     int i = 5;
//     while(i)
//     {
//         if (read(fd, str, 6) != -1)
//             printf("%s\n", str);
//         i--;
//     }     
//     return 0;
// }
