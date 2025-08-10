#include "../LIBFT/libft.h"
#include "../includes/so_long.h"
#include <stdio.h>
#include "../minilibx-linux/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h> 


static char **grow_map(char **map, int old_size, int new_size)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(sizeof(char *) * new_size);
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new_map[i] = map[i];
		i++;
	}
	free(map);
	return (new_map);
}

char	**load_map(const char *filename)
{
    int		fd;
    char	**map;
    char	*line;
    int		lines_allocated = 16;
    int		line_count = 0;

    printf("DEBUG: Tentando abrir arquivo '%s'\n", filename);
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        printf("DEBUG: Falha ao abrir arquivo!\n");
        return (NULL);
    }
    map = (char **)malloc(sizeof(char *) * lines_allocated);
    if (!map) {
        printf("DEBUG: Falha no malloc!\n");
        return(NULL);
    }
    while ((line = get_next_line(fd)))
    {
        printf("DEBUG: Linha lida: '%s'\n", line);
        if (line_count >= lines_allocated)
        {
            lines_allocated *= 2;
            map = grow_map(map, line_count, lines_allocated);
            if (!map)
            {
                printf("DEBUG: Falha no grow_map!\n");
                close(fd);
                return (NULL);
            }
        }
        int len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
        map[line_count++] = line;
    }
    map[line_count] = NULL;
    close(fd);
    printf("DEBUG: Linhas carregadas: %d\n", line_count);
    return (map);
}

void	free_map(char **map)
{
	int i = 0;

	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
