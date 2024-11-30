#include "get_next_line.h"

// int main()
// {
//     char *str = NULL;
//     printf("%s\n",str);
// }

int main()
{
    int fd = open("file.txt", O_CREAT | O_RDONLY, 0640);
    char *s= get_next_line(fd);
    if (fd == -1)
        return 2;
    int i = 0;
    while (i < 15)
    {i++;
        printf("%s", s);
        free(s);
        s= get_next_line(fd);
    }
  //  system("leaks a.out");
    return (0);
}