/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:39:28 by hfegrach          #+#    #+#             */
/*   Updated: 2024/11/23 13:18:57 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    
}

int main()
{
    char *str = malloc(10);
    int fd = open("file.txt", O_CREAT | O_RDONLY, 0640);
    if (fd == -1)
        return 2;
    int i = 5;
    while(i)
    {
        if (read(fd, str, 6) != -1 != -1)
            printf("%s\n", str);
        i--;
    }     
    return 0;
}
