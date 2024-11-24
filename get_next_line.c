/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:39:28 by hfegrach          #+#    #+#             */
/*   Updated: 2024/11/24 17:09:53 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *s;
    char *buff;
    char *line;
    char *tmp;
    
    if (fd < 0)
    {
        buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
        read(fd, buff, BUFFER_SIZE);
        str = ft_strdup(buff);
        while (1)
        {
            if (is_line(buff))
            {
                line = read_line(buff);
                break;
            }
            else
            {
                read(fd, buff, BUFFER_SIZE);
                line = ft_strjoin()
            }
        }
    }
}









































































// char *ft_read(int fd, char *s)
// {
//     read(fd, s, 5);
//     return s;
// }

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

// void    ft_clean(char *s, int n)
// {
//     return;
// }

char *get_next_line(int fd)
{
    static char *str;
    char *line;
    char *tmp;
    
    if (fd == -1)
        return NULL;
    if (!str)
        str = malloc(BUFFER_SIZE + 1);
    if(!str)
        return (NULL);
    read(fd, str, BUFFER_SIZE);
    line = read_line(str);
    tmp = ft_strdup(ft_strchr(str, '\n') + 1);
    free(str);
    str = ft_strdup(tmp);
    return line;
}
/*---------------------------MAIN--------------------------------*/
int main()
{
    int fd = open("file.txt", O_CREAT | O_RDONLY, 0640);
    if (fd == -1)
        return 2;
    int i = 0;
    while (i < 5)
    {
        printf("%s", get_next_line(fd));
        i++;
    }
    return (0);
}

// int main()
// {
//     int fd = open("file.txt", O_CREAT | O_RDONLY, 0640);
//     if (fd == -1)
//         return 2;
//     char *s = calloc(10, sizeof(char));
//     //s = "hello cv kolchi mzyan";
//     printf("%s\n",ft_read(fd, s));
//     printf("%s\n",ft_read(fd, s));
//     printf("%s\n",ft_read(fd, s));
//     printf("%s\n",ft_read(fd, s));
// }

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
