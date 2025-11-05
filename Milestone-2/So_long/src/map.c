/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:33:46 by lmanzani          #+#    #+#             */
/*   Updated: 2025/11/05 17:21:07 by lmanzani         ###   ########.fr       */
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
	while (i < new_size)
	{
		new_map[i] = NULL;
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
    int 	len;
    
    fd = open(filename, O_RDONLY);
    if (fd < 0) 
    {
		close(fd);
        return (NULL);
    }
    map = (char **)malloc(sizeof(char *) * lines_allocated);
    if (!map) 
    {
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
                close(fd);
                return (NULL);
            }
        }
	len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
        map[line_count++] = line;
    }
    map[line_count] = NULL;
    close(fd);
    return (map);
}

void	free_map(char **map, int rows)
{
	int 	i;
	i = 0;

	if (!map)
		return ;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
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
