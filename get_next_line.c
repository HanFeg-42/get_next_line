/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:39:28 by hfegrach          #+#    #+#             */
/*   Updated: 2024/11/28 11:17:46 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*==========================FIFTH TRY=============================*/

char    *get_next_line(int fd)
{
    static char *save;
    char *buff;
    
    
}































/*==========================FORTH TRY=============================*/

//use only ==>
/*
    *FT_STRCHR
    *FT_STRDUP
    *FT_STRLEN
    *FT_SUBSTR
    *FT_STRJOIN
*/

// char    *get_next_line(int fd)
// {
//     static char *str;
//     char (*buff) ,(*line), (*tmp);
//     ssize_t rd;

//     if(fd < 0 || BUFFER_SIZE < 0)
//         return (NULL);
//     buff = malloc((BUFFER_SIZE + 1 ) * sizeof(char));
//     if (!buff)
//         return (NULL);
//     while (1)
//     {
//         if (str != NULL && ft_strchr(str, '\n'))
//         {
//             line = ft_substr(str, 0, ft_strchr(str, '\n') - str + 1);
//             if (!line)
//                 return (free(buff),free(str), str = NULL,  buff = NULL,free(line), line = NULL, NULL);
//             return (str = ft_strchr(str, '\n') + 1,free(str), str = NULL,  free(buff), buff = NULL, line);
//         }
//         else
//         {
//             rd = read(fd, buff, BUFFER_SIZE);
//             if (!rd)
//             {
//                 if (rd == 0 && str != NULL)
//                     return (tmp = ft_strdup(str),free(str), str = NULL, free(buff), buff = NULL, tmp);
//                 return (free(str), str = NULL, free(buff), buff = NULL, NULL);
//             }
//             buff[rd] = '\0';
//             if (!str)
//                 str = ft_strdup(buff);
//             else
//                 str = ft_strjoin(str, buff);
//         }
//     }
// }




































/*==========================THIRD TRY=============================*/

//---------------------------segfault-----------------------------//

// char *get_next_line(int fd)
// {
//     static char *str;
//     char *buff;
//     char *tmp;
//     char *tst;
//     ssize_t rd;
    
//     if (fd >= 0)
//     {
//         buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
//         while (1)
//         {
//             rd = read(fd, buff, BUFFER_SIZE);
//             if (rd == -1 || rd == 0)
//             {
//                 if (!rd && str != NULL)
//                 {
//                     tst = ft_strdup(str);
//                     return (free(str), tst);
//                 }
//                 return (free(buff), NULL);
//             }
//             if(!str)
//                 str = ft_strdup(buff);
//             else
//                 str = ft_strjoin(str, buff);
//             tmp = ft_strchr(str, '\n');
//             if (tmp)
//             {
//                 str = ft_strchr(str, '\n') + 1;
//                 return (ft_substr(str, 0, tmp - str + 1));exit(0);
//             }
//         }
//     }
//     return (NULL);
// }
/*---------------------------MAIN--------------------------------*/
// int main()
// {
//     int fd = open("file.txt", O_CREAT | O_RDONLY, 0640);
//     if (fd == -1)
//         return 2;
//     int i = 0;
//     while (i < 15)
//     {
//         printf("%s", get_next_line(fd));
//         i++;
//     }
//     return (0);
// }

















































































/*===============================SECOND TRY=======================================*/

/*=========================Correct output but full of leaks=======================*/

// char *read_line(char *s)
// {
//     int len;
//     char *ret;
//     int i;

//     if(!s)
//         return (NULL);
//     len = 0;
//     while(s[len] != '\n')
//         len++;
//     ret = malloc(len + 2);
//     if (!ret)
//         return (NULL);
//     i = 0;
//     while(s[i] != '\n')
//     {
//         ret[i] = s[i];
//         i++;
//     }
//     ret[i++] = '\n';
//     ret[i] = '\0';
//     return (ret);
// }

// int is_line(char *s)
// {
//     if (!s)
//         return (0);
//     while(*s)
//     {
//         if (*s == '\n')
//             return (1);
//         s++;
//     }
//     return (0);
// }

// char    *get_next_line(int fd)
// {
//     static char *str;
//     char *buff;
//     char *line;
//     ssize_t rd;
//     char *tmp;
    
//     if (fd > 0)
//     {
//         tmp = NULL;
//         rd = 0;
//         buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
//         while (1)
//         {
//             if (is_line(str))
//             {
//                 line = read_line(str);
//                 str = ft_strchr(str, '\n') + 1;  
//                 return (free(buff), buff = NULL, line);
//             }
//             else
//             {
//                 rd = read(fd, buff, BUFFER_SIZE);
//                 buff[rd] = '\0';
//                 if (rd == -1 || rd == 0)
//                 {
//                     if (!rd && str != NULL)
//                     {
//                         tmp = ft_strdup(str);
//                         return (free(buff), buff = NULL, str = NULL, tmp);
//                     }
//                     return (free(buff), buff = NULL, NULL);
//                 }
//                 if (!str)
//                     str = ft_strdup(buff);
//                 else
//                     str = ft_strjoin(str, buff);
                
//             }
//         }
//     }
//     return (NULL);
// }
/*---------------------------MAIN--------------------------------*/
// int main()
// {
//     int fd = open("file.txt", O_CREAT | O_RDONLY, 0640);
//     if (fd == -1)
//         return 2;
//     int i = 0;
//     while (i < 15)
//     {
//         printf("%s", get_next_line(fd));
//         i++;
//     }
//     return (0);
// }




































































/*==========================FIRST TRY=============================*/



// char *ft_read(int fd, char *s)
// {
//     read(fd, s, 50);
//     return s;
// }
// int main()
// {
//     int fd = open("test.txt", O_RDONLY, 0777);
//     char s[10];
//     printf("%d\n", read(fd, s, 5));
// }
//==========================================================
// char *read_line(char *s)
// {
//     int len;
//     char *ret;
//     int i;

//     if(!s)
//         return (NULL);
//     len = 0;
//     while(s[len] != '\n')
//         len++;
//     ret = malloc(len + 2);
//     if (!ret)
//         return (NULL);
//     i = 0;
//     while(s[i] != '\n')
//     {
//         ret[i] = s[i];
//         i++;
//     }
//     ret[i++] = '\n';
//     ret[i] = '\0';
//     return (ret);
// }

// void    ft_clean(char *s, int n)
// {
//     return;
// }

// char *get_next_line(int fd)
// {
//     static char *str;
//     char *line;
//     char *tmp;
    
//     if (fd == -1)
//         return NULL;
//     if (!str)
//         str = malloc(BUFFER_SIZE + 1);
//     if(!str)
//         return (NULL);
//     read(fd, str, BUFFER_SIZE);
//     line = read_line(str);
//     tmp = ft_strdup(ft_strchr(str, '\n') + 1);
//     free(str);
//     str = ft_strdup(tmp);
//     return line;
// }
// /*---------------------------MAIN--------------------------------*/
// int main()
// {
//     int fd = open("file.txt", O_CREAT | O_RDONLY, 0640);
//     if (fd == -1)
//         return 2;
//     int i = 0;
//     while (i < 5)
//     {
//         printf("%s", get_next_line(fd));
//         i++;
//     }
//     return (0);
// }

// int main()
// {
//     int fd = open("test.txt", O_CREAT | O_RDONLY, 0640);
//     if (fd == -1)
//         return 2;
//     char *s = calloc(20, sizeof(char));
//     //s = "hello cv kolchi mzyan";
//     printf("%s\n",ft_read(fd, s));
//     // printf("%s\n",ft_read(fd, s));
//     // printf("%s\n",ft_read(fd, s));
//     // printf("%s\n",ft_read(fd, s));
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
