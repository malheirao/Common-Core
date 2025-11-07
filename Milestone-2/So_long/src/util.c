/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:37:15 by lmanzani          #+#    #+#             */
/*   Updated: 2025/11/07 19:37:28 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include "../LIBFT/libft.h"

void	collect_counter(t_vars *game)
{
	int	x;
	int	y;

	game->total_collectibles = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->total_collectibles++;
			x++;
		}
		y++;
	}
	if (game->total_collectibles == 0)
	{
		ft_printf("You must have at least one collectible\n");
		exit_game(game);
	}
}

void	finish_game(t_vars *game)
{
	if (game->map[game->player_y][game->player_x] == 'E' &&
		game->collected == game->total_collectibles)
	{
		ft_printf("YOU WON! Moves: %d\n", game->move_count);
		exit_game(game);
	}
}

static int	check_unreachable(char **map_copy, int rows, int cols)
{
	int	y;
	int	x;
	int	valid;

	valid = 1;
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
				valid = 0;
			x++;
		}
		y++;
	}
	return (valid);
}

void	general_parser(t_vars *game)
{
	check_players(game);
	check_exits(game);
	check_surrounded(game);
	random_char_verify(game);
	collect_counter(game);
	player_pos(game->map, &game->player_x, &game->player_y);
	if (game->player_x == -1 || game->player_y == -1)
	{
		ft_printf("Player not found!\n");
		exit_game(game);
	}
	if (!is_map_valid(game))
	{
		ft_printf("Map is not valid!\n");
		exit_game(game);
	}
}

int	is_map_valid(t_vars *game)
{
	char	**map_copy;

	map_copy = dup_map(game->map, game->map_rows, game->map_columns);
	if (!map_copy)
		return (0);
	map_copy[game->player_y][game->player_x] = '0';
	fill(map_copy, game->map_rows, game->map_columns, '0',
		game->player_y, game->player_x);
	if (!check_unreachable(map_copy, game->map_rows, game->map_columns))
	{
		free_map(map_copy, game->map_rows);
		return (0);
	}
	free_map(map_copy, game->map_rows);
	return (1);
}
