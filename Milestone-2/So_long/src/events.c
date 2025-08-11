/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:43:37 by lmanzani          #+#    #+#             */
/*   Updated: 2025/08/11 19:00:07 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include "../LIBFT/libft.h"

void collect(t_vars *game)
{
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->collected++;
		game->map[game->player_y][game->player_x] = '0';
				ft_printf("Coletados: %d de %d\n", game->collected, game->total_collectibles);
		total_collected(game);
	}
}

void total_collected(t_vars *game)
{
	if(game->collected == game->total_collectibles)
	{
		game->exit_open = 1;
		update_window(game);
	}
}
