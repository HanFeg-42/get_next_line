/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:39:28 by hfegrach          #+#    #+#             */
/*   Updated: 2024/11/30 15:40:51 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*========================YARBI TKOUN THE LAST TRY=======================*/
// ------------------it works --------------------------do not touch it----

void    fill_in_save(int fd, ssize_t *rd, char **save, char **buff)
{
    while (1)
    {
        *rd = read(fd, *buff, BUFFER_SIZE);
        if (*rd == 0 || *rd == -1)
            break;
        (*buff)[*rd] = '\0';
        if (!(*save))
            *save = ft_strdup(*buff);
        else
            *save = ft_strjoin(*save, *buff);
        if (!(*save))
            break;
        if (ft_strchr(*save, '\n')) 
            break;
    }
}

char    *test(char **save)
{
    char *tmp;
    
    tmp = ft_strdup(*save);
    if(!tmp)
        return( *save = NULL, NULL);
    return (free(*save), *save = NULL, tmp);
}

char    *read_line(char **save)
{
    char (*line), (*new);
    
    line = ft_substr(*save, 0, ft_strchr(*save, '\n') - *save + 1);
    if (!line)
        return (free(line), line = NULL,  NULL);
    new = ft_strdup(ft_strchr(*save, '\n') + 1); 
    if(!new)
        return(free(*save),free(line), *save = NULL, NULL);
    free(*save);
    *save = ft_strdup(new);
    if (!(*save))
        return (free(new), free(line),*save = NULL, NULL);
    return (free(new), line);
}

char    *get_next_line(int fd)
{
    static char *save;
    char (*buff);
    ssize_t rd;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buff = malloc((BUFFER_SIZE * sizeof(char)) + 1);
    if (!buff)
        return (NULL);
    fill_in_save(fd, &rd, &save, &buff);
    free (buff);
    if (save != NULL && ft_strchr(save, '\n'))
        return (read_line(&save));
    else if (!rd && save != NULL)
        return (test(&save));
    return (NULL);
}



































/*==========================TRY NUMBER 7=============================*/

// void    fill_in_save(int fd, ssize_t *rd, char **save, char **buff)
// {
//     while (1)
//     {
//         *rd = read(fd, *buff, BUFFER_SIZE);
//         if (*rd == 0 || *rd == -1)
//             break;
//         // {
//         //     if (*rd == 0)
//         //         break;
//         //     return (free(*buff), *buff = NULL, NULL);
//         // }
//         (*buff)[*rd] = '\0';
//         if (!(*save))
//             *save = ft_strdup(*buff);
//         else
//             *save = ft_strjoin(*save, *buff);//printf("%s\n", save);
//         if (!(*save))
//             break;
//             // return (free(*buff), *buff = NULL, NULL);
//         if (ft_strchr(*save, '\n')) 
//             break;
//     }
// }

// char    *test(char **save)
// {
//     char *tmp;
//     tmp = ft_strdup(*save);
//     if(!tmp)
//         return( *save = NULL, NULL);
//     return (free(*save), *save = NULL, tmp);
// }
// char    *read_line(char **save)
// {
//     char (*line), (*new), (*tmp);
    
//     // if (save != NULL && ft_strchr(save, '\n'))
//     // {
//         line = ft_substr(*save, 0, ft_strchr(*save, '\n') - *save + 1);
//         if (!line)
//             return (free(line), line = NULL,  NULL);
//         new = ft_strdup(ft_strchr(*save, '\n') + 1); 
//         if(!new)
//             return(free(*save),free(line), *save = NULL, NULL);
//         free(*save);
//         *save = ft_strdup(new);
//         if (!(*save))
//             return (free(new), free(line),*save = NULL, NULL);
//         return (free(new), line);
//     // }
//     // else if (!rd && save != NULL)
//     // {
//     //     tmp = ft_strdup(*save);
//     //     if(!tmp)
//     //         return( *save = NULL, NULL);
//     //     return (free(*save), *save = NULL, tmp);
//     // }

// }
// char    *get_next_line(int fd)
// {
//     static char *save;
//     char (*buff);
//     ssize_t rd;
    
//     if (fd < 0 || BUFFER_SIZE <= 0)
//         return (NULL);
//     buff = malloc((BUFFER_SIZE * sizeof(char)) + 1); // when i do this (BUFFER_SIZE * sizeof(char)) i tell the compiler cat it to size_t
//     if (!buff)
//         return (NULL);
//     fill_in_save(fd, &rd, &save, &buff);
//     // while (1)
//     // {
//     //     rd = read(fd, buff, BUFFER_SIZE);
//     //     if (rd == 0 || rd == -1)
//     //     {
//     //         if (rd == 0)
//     //             break;
//     //         return (free(buff), buff = NULL, NULL);
//     //     }
//     //     buff[rd] = '\0';
//     //     if (!save)
//     //         save = ft_strdup(buff);
//     //     else
//     //         save = ft_strjoin(save, buff);//printf("%s\n", save);
//     //     // if (!save)
//     //     //     return (free(buff), buff = NULL, NULL);
//     //     if (ft_strchr(save, '\n')) 
//     //         break;
//     // }
//     free (buff);
//     if (save != NULL && ft_strchr(save, '\n'))
//         return (read_line(&save));
//     else if (!rd && save != NULL)
//         return (test(&save));
//     return (NULL);
// }


















































/*==========================N 6=============================*/

//  total heap usage: 76 allocs, 72 frees, 1,451 bytes allocated

// good output

// char    *get_next_line(int fd)
// {
//     static char *save;
//     char (*buff), (*line), (*tmp), (*new);
//     ssize_t rd;
    
//     if (fd < 0 || BUFFER_SIZE <= 0)
//         return (NULL);
//     buff = malloc((BUFFER_SIZE * sizeof(char)) + 1); // when i do this (BUFFER_SIZE * sizeof(char)) i tell the compiler cat it to size_t
//     if (!buff)
//         return (NULL);
//     while (1)
//     {
//         rd = read(fd, buff, BUFFER_SIZE);
//         if (rd == 0 || rd == -1)
//         {
//             if (rd == 0)
//                 break;
//             return (free(buff), buff = NULL, NULL);
//         }
//         buff[rd] = '\0';
//         if (!save)
//             save = ft_strdup(buff);
//         else
//             save = ft_strjoin(save, buff);//printf("%s\n", save);
//         if (!save)
//             return (free(buff), buff = NULL, NULL);
//         if (ft_strchr(save, '\n')) 
//             break;
//     }
//     if (save != NULL && ft_strchr(save, '\n'))
//     {
//         line = ft_substr(save, 0, ft_strchr(save, '\n') - save + 1);
//         if (!line)
//             return (free(save),free(buff), buff = NULL, free(line), line = NULL,  NULL);
//         new = ft_strdup(ft_strchr(save, '\n') + 1); 
//         if(!new)
//             return(free(save),save = NULL,free(buff), buff = NULL,NULL);
//         return (free(save),free(buff), buff = NULL,save = ft_strdup(new),free(new) , line);
//     }
//     if (!rd && save != NULL)
//     {
//         tmp = ft_strdup(save);
//         if(!tmp)
//             return(free(buff), buff = NULL, free(save), save = NULL, NULL);
//         return (free(buff), buff = NULL, free(save), save = NULL, tmp);
//     }
//     return (NULL);
// }



























































/*==========================FIFTH TRY=============================*/

//=======================correct output===========================//
/*
valgrind ./a.out 
==1082911==     in use at exit: 852 bytes in 15 blocks
==1082911==   total heap usage: 48 allocs, 33 frees, 3,606 bytes allocated
*/

// char    *get_next_line(int fd)
// {
//     static char *save;
//     char (*buff), (*line), (*tmp), (*new);
//     ssize_t rd;
    
//     if (fd < 0 || BUFFER_SIZE <= 0)
//         return (NULL);
//     buff = malloc((BUFFER_SIZE * sizeof(char)) + 1); // when i do this (BUFFER_SIZE * sizeof(char)) i tell the compiler cat it to size_t
//     if (!buff)
//         return (NULL);
//     rd = 1;
//     while (rd)
//     {
//         rd = read(fd, buff, BUFFER_SIZE);
//         if (rd == 0 || rd == -1)
//         {
//             if (rd == 0)
//                     break;
//             return (free(buff), buff = NULL, NULL);
//         }
//         buff[rd] = '\0';
//         if (!save)
//             save = ft_strdup(buff);
//         else
//             save = ft_strjoin(save, buff);//printf("%s\n", save);
//             if (!save)
//                 return (free(buff), buff = NULL, NULL);
//         if (ft_strchr(save, '\n')) 
//             break;
//     }
//     if (save != NULL && ft_strchr(save, '\n'))
//     {
//         line = ft_substr(save, 0, ft_strchr(save, '\n') - save + 1);
//         if (!line)
//             return (free(buff), buff = NULL, free(line), line = NULL,  NULL);
//         new = ft_strdup(ft_strchr(save, '\n') + 1); 
//         if(!new)
//             return(free(save),save = NULL,free(buff), buff = NULL,NULL);
//         return (free(save),free(buff), buff = NULL,save = ft_strdup(new) , line);
//     }
//     if (!rd && save != NULL)
//         return (free(buff), buff = NULL, tmp = ft_strdup(save),save = NULL, tmp);
//     return (NULL);
// }




























/*==========================FORTH TRY=============================*/
//==========================kant khdama=====db la=================//
/*
munmap_chunk(): invalid pointer
[1]    235302 IOT instruction (core dumped)  ./a.out
*/

//use oft_strchr(save, '\n')y ==>
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
//                 return (free(buff),  buff = NULL,free(line), line = NULL, NULL);
//             return (str = ft_strchr(str, '\n') + 1,  free(buffchar *read_line(char *s)
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
// }), buff = NULL, line);
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
//             {exit(0);
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
//                 return (ft_substr(str, 0, tmp - str + 1));
//             }
//         }
//     }
//     return (NULL);
// }
/*---------------------------MAIN--------------------------------*/
// int main()
// {
//     int fd = open("file.txt", O_CREAT | O_RDOft_strchr(save, '\n')Y, 0640);
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
//     int fd = open("test.txt", O_RDOft_strchr(save, '\n')Y, 0777);
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
//     int fd = open("file.txt", O_CREAT | O_RDOft_strchr(save, '\n')Y, 0640);
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
//     int fd = open("test.txt", O_CREAT | O_RDOft_strchr(save, '\n')Y, 0640);
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
//     int fd = open("file.txt", O_CREAT | O_RDOft_strchr(save, '\n')Y, 0640);
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
