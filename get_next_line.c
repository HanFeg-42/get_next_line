/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:39:28 by hfegrach          #+#    #+#             */
/*   Updated: 2024/11/23 22:41:32 by hfegrach         ###   ########.fr       */
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
    {
        ret[i] = s[i];
        i++;
    }
    ret[i++] = '\n';
    ret[i] = '\0';
    return (ret);
}

void    ft_clean(char *s, int n)
{
    return;
}

char *get_next_line(int fd)
{
    static char *str;
    char *line;
    
    if (fd == -1)
        return NULL;
    if (!str)
    str = malloc(BUFFER_SIZE + 1);
    if(!str)
    return (NULL);
    if (read(fd, str, BUFFER_SIZE) != -1)
        //printf("%s\n", str);
    line = read_line(str);
    str = ft_strchr(str, '\n') + 1;
    ft_clean(str, ft_strlen(line));
    return line;
}

int main()
{
    int fd = open("file.txt", O_CREAT | O_RDONLY, 0640);
    if (fd == -1)
        return 2;
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
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
