#include "get_next_line.h"

// int main()
// {
//     char *str = NULL;
//     printf("%s\n",str);
// }

int main()
{
    int fd = open("file.txt", O_CREAT | O_RDONLY, 0640);
    if (fd == -1)
        return 2;
    int i = 0;
    while (i < 15)
    {
        printf("%s", get_next_line(fd));
        i++;
    }
    return (0);
}