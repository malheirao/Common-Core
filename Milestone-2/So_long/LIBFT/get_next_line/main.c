#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int     fd;
    char    *line;
	fd = open("get_next_line.c", O_RDONLY);
    while ((line = get_next_line(fd)))
	{
		printf("Linha: %s", line);
		free(line);
	}
	close(fd);
    return (0);
}
