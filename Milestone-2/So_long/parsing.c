#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
char **parse_map(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return NULL;

    char **map = malloc(sizeof(char *) * 10000); // até 10.000 linhas
    int i = 0;
    char *line;

    while ((line = get_next_line(fd)))
        map[i++] = line;

    map[i] = NULL;
    close(fd);
    return map;
}
void free_map(char **map)
{
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Uso: %s caminho/para/mapa.ber\n", argv[0]);
        return 1;
    }

    char **map = parse_map(argv[1]);
    if (!map)
    {
        printf("Erro ao abrir ou ler o mapa!\n");
        return 1;
    }

    printf("Mapa lido:\n");
    for (int i = 0; map[i]; i++)
        printf("%s", map[i]); // get_next_line já inclui o \n

    free_map(map);
    return 0;
}
