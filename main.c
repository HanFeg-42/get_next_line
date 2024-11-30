#include "get_next_line.h"

// int main()
// {
//     char *str = NULL;
//     printf("%s",str);
// }

int main()
{
    //int fd = open("test_empty", O_CREAT | O_RDONLY | O_TRUNC, 0640);
    // int fd=open("/dev/null",O_RDONLY);
    int fd = open("file.txt", O_CREAT | O_RDONLY, 0640);
    char *s;
    // if (fd == -1)
    //     return 2;
    int i = 0;
    while (i < 15)
    {i++;s= get_next_line(fd);
        printf("%s", s);
        free(s);
        
    }
  //  system("leaks a.out");
    return (0);
}
