/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:43:37 by lmanzani          #+#    #+#             */
/*   Updated: 2025/11/07 23:29:10 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include "../LIBFT/libft.h"

void	collect(t_vars *game)
{
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->collected++;
		game->map[game->player_y][game->player_x] = '0';
		ft_printf("Collected:%d of %d\n", game->collected,
			game->total_collectibles);
		total_collected(game);
	}
}

void	total_collected(t_vars *game)
{
	if (game->collected == game->total_collectibles)
	{
		game->exit_open = 1;
		update_window(game);
	}
}

void	free_map(char **map, int rows)
{
	int	i;

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
	int	i;
	int	j;

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
				return ;
			}
			j++;
		}
		i++;
	}
	*x = -1;
	*y = -1;
}
