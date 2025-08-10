/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:40:19 by lmanzani          #+#    #+#             */
/*   Updated: 2025/06/04 16:20:53 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = 1;
	while (!gnl_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free (buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!stash || stash[i] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(i + (stash[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*stash_substr_after_nl(char *stash, size_t i)
{
	size_t	j;
	char	*new_stash;

	j = 0;
	new_stash = (char *)malloc(gnl_strlen(stash + i) + 1);
	if (!new_stash)
		return (NULL);
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	return (new_stash);
}

static char	*clean_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = stash_substr_after_nl(stash, i);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char **av)
{
    int     fd;
    char    *line;
	fd = open(av[1], O_RDONLY);
    while ((line = get_next_line(fd)))
	{
		printf("Linha: %s", line);
		free(line);
	}
	close(fd);
    return (0);
}*/
