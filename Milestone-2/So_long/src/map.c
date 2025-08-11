/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:33:46 by lmanzani          #+#    #+#             */
/*   Updated: 2025/08/11 19:15:43 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include "../LIBFT/libft.h"

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

    ft_printf("DEBUG: Tentando abrir arquivo '%s'\n", filename);
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        ft_printf("DEBUG: Falha ao abrir arquivo!\n");
        return (NULL);
    }
    map = (char **)malloc(sizeof(char *) * lines_allocated);
    if (!map) {
        ft_printf("DEBUG: Falha no malloc!\n");
        return(NULL);
    }
    while ((line = get_next_line(fd)))
    {
        if (line_count >= lines_allocated)
        {
            lines_allocated *= 2;
            map = grow_map(map, line_count, lines_allocated);
            if (!map)
            {
               ft_printf("DEBUG: Falha no grow_map!\n");
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
int count_collec(char **map)
{
    int x, y, count = 0;
    for (y = 0; map[y]; y++)
        for (x = 0; map[y][x]; x++)
            if (map[y][x] == 'C')
                count++;
    return count;
}

void	player_pos(char **map, int *x, int *y)
{
	int i;
	int j;

	i = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return;
			}
			j++;
		}
		i++;
	}
	*x = -1;
	*y = -1;
}
