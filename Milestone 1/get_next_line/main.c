#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc == 1)
    {
        // Lê do stdin caso nenhum arquivo seja passado
        printf("Digite linhas (Ctrl+D para finalizar):\n");
        while ((line = get_next_line(0)) != NULL)
        {
            printf("Linha: %s", line);
            free(line);
        }
    }
    else
    {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
            perror("Erro ao abrir o arquivo");
            return (1);
        }
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("Linha: %s", line);
            free(line);
        }
        close(fd);
    }
    return (0);
}
