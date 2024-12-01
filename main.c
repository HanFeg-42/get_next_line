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
    int fd = open("nos.txt", O_CREAT | O_RDWR, 0640);
    // write(fd, "nouss is\nvery\nbeautiful\nwa chokran", 34);
    // close(fd);
    // fd = open("nos.txt", O_CREAT | O_RDWR, 0640);

    char *s=get_next_line(fd);
    // if (fd == -1)
    //     return 2;

    while (s)
    {
        printf("%s", s);
        free(s);
        s = get_next_line(fd);
        printf("i have ---%s----", s);
    }
    // s = get_next_line(fd);
    printf("--%s--", s);
    //system("leaks a.out");
    return (0);
}
