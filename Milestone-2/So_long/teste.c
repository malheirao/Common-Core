#include <stdio.h>
#include <fcntl.h>
#include "LIBFT/get_next_line/get_next_line.h" // Inclua corretamente o cabeçalho

int main(void)
{
    int fd = open("maps/map1.ber", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
       printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
