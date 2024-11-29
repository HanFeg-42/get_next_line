#include "get_next_line.h"

// int main()
// {
//     char *str = NULL;
//     printf("%s\n",str);
// }

int main()
{
    int fd = open("file.txt", O_CREAT | O_RDONLY, 0640);
    char *s;
    if (fd == -1)
        return 2;
    int i = 0;
    while (i < 15)
    {
        s = get_next_line(fd);
        printf("%s", s);
        i++;
        free(s);
        s = NULL;
    }
    return (0);
}