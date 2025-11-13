/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:55:42 by lmanzani          #+#    #+#             */
/*   Updated: 2025/11/10 16:05:35 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include "../LIBFT/libft.h"

static int	is_valid_char(char tile)
{
	char	valid_tiles[6];
	int		i;

	valid_tiles[0] = '0';
	valid_tiles[1] = '1';
	valid_tiles[2] = 'P';
	valid_tiles[3] = 'E';
	valid_tiles[4] = 'C';
	valid_tiles[5] = '\0';
	i = 0;
	while (valid_tiles[i] != '\0' && tile != valid_tiles[i])
		i++;
	return (valid_tiles[i] != '\0');
}

void	check_players(t_vars *game)
{
	int	players;
	int	y;
	int	x;

	players = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				players++;
			x++;
		}
		y++;
	}
	if (players != 1)
	{
		ft_printf("Error\nYou must have exactly 1 player!\n");
		exit_game(game);
	}
}

void	check_exits(t_vars *game)
{
	int	exits;
	int	y;
	int	x;

	exits = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				exits++;
			x++;
		}
		y++;
	}
	if (exits != 1)
	{
		ft_printf("Error\nYou must have exactly 1 exit!\n");
		exit_game(game);
	}
}

void	check_surrounded(t_vars *game)
{
	int	y;

	y = 0;
	while (y < game->map_rows)
	{
		if (game->map[y][0] != '1' ||
			game->map[y][game->map_columns - 1] != '1')
		{
			ft_printf("Error\nMap not surrounded by walls!\n");
			exit_game(game);
		}
		y++;
	}
	y = 0;
	while (y < game->map_columns)
	{
		if (game->map[0][y] != '1' || game->map[game->map_rows - 1][y] != '1')
		{
			ft_printf("Error\nMap not surrounded by walls!\n");
			exit_game(game);
		}
		y++;
	}
}

void	random_char_verify(t_vars *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (!is_valid_char(game->map[y][x]))
			{
				ft_printf("Error\nInvalid char on the map\n");
				exit_game(game);
			}
			x++;
		}
		y++;
	}
}
