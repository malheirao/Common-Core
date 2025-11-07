/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:52:59 by lmanzani          #+#    #+#             */
/*   Updated: 2025/11/07 19:24:09 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include "../LIBFT/libft.h"

void	fill(char **tab, int rows, int cols, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= rows || col >= cols)
		return ;
	if (tab[row][col] == 'F')
		return ;
	if (tab[row][col] != target && tab[row][col] != 'C' && tab[row][col] != 'E')
		return ;
	tab[row][col] = 'F';
	fill(tab, rows, cols, target, row, col + 1);
	fill(tab, rows, cols, target, row, col - 1);
	fill(tab, rows, cols, target, row + 1, col);
	fill(tab, rows, cols, target, row - 1, col);
}

static void	free_dup(char **copy, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

char	**dup_map(char **original, int rows, int cols)
{
	char	**copy;
	int		i;
	int		j;

	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		copy[i] = malloc(sizeof(char) * (cols + 1));
		if (!copy[i])
		{
			free_dup(copy, i);
			return (NULL);
		}
		j = 0;
		while (j < cols)
		{
			copy[i][j] = original[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[rows] = NULL;
	return (copy);
}

void	flood_fill(t_vars *game)
{
	char	target;

	target = game->map[game->player_y][game->player_x];
	fill(game->map, game->map_rows, game->map_columns, target, game->player_y, game->player_x);
}
