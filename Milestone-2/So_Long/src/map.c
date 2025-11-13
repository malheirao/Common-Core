/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:01:29 by lmanzani          #+#    #+#             */
/*   Updated: 2025/11/07 23:13:23 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include "../LIBFT/libft.h"

static char	**grow_map(char **map, int old_size, int new_size)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(sizeof(char *) * new_size);
	if (!new_map || (!new_size))
	{
		free_map(map, old_size);
		return (NULL);
	}
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

static char	**allocate_map(int *fd, const char *filename, int *lines_allocated)
{
	char	**map;

	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (NULL);
	*lines_allocated = 16;
	map = (char **)malloc(sizeof(char *) * *lines_allocated);
	if (!map)
		close(*fd);
	return (map);
}

static int	proc_line(char ***map, char *line, int *line_count, int *line_alloc)
{
	int	len;

	if (*line_count >= *line_alloc)
	{
		*line_alloc *= 2;
		*map = grow_map(*map, *line_count, *line_alloc);
		if (!*map)
		{
			free(line);
			return (0);
		}
	}
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	(*map)[(*line_count)++] = line;
	return (1);
}

static int	validate_lines(char **map, int line_count)
{
	int	expected_cols;
	int	i;

	if (line_count <= 0)
		return (1);
	expected_cols = ft_strlen(map[0]);
	i = 1;
	while (i < line_count)
	{
		if ((int)ft_strlen(map[i]) != expected_cols)
			return (0);
		i++;
	}
	return (1);
}

char	**load_map(const char *filename)
{
	int		fd;
	char	**map;
	char	*line;
	int		lines_allocated;
	int		line_count;

	map = allocate_map(&fd, filename, &lines_allocated);
	if (!map)
		return (free_map(map, 0), NULL);
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!proc_line(&map, line, &line_count, &lines_allocated))
		{
			close(fd);
			return (free_map(map, line_count), NULL);
		}
		line = get_next_line(fd);
	}
	map[line_count] = NULL;
	close(fd);
	if (!validate_lines(map, line_count))
		return (free_map(map, line_count), NULL);
	return (map);
}
