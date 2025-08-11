/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:53:27 by lmanzani          #+#    #+#             */
/*   Updated: 2025/08/11 16:45:38 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include "../LIBFT/libft.h"

#define TILE_SIZE 32

//desenha tile especifico na posicao (x, y)
void	draw_tile(t_vars *game, void *img, int x, int y)
{
	int	offset_x;
	int	offset_y;

	offset_x = 0;
	offset_y = 0;
	mlx_put_image_to_window(game->mlx, game-> win, img,
			offset_x + x * TILE_SIZE, offset_y + y * TILE_SIZE);
}

void	draw_map(t_vars *game)
{
	ft_printf("[DEBUG] Entrou em draw_map\n");
	int		x;
	int		y;
	char	tile;

	y = 0;
	while(game->map[y])
	{
		ft_printf("[DEBUG] y=%d, game->map[y]=%p, linha='%s'\n", y, (void*)game->map[y], game->map[y]);
		x = 0;
		while(game-> map[y][x])
		{
			tile = game->map[y][x];
			ft_printf("[DEBUG] x=%d, y=%d, tile=%c\n", x, y, tile);
			draw_tile(game, game->img_floor, x, y);
			if (tile == '1')
				draw_tile(game, game->img_wall, x, y);
			else if (tile == 'C')
				draw_tile(game, game->img_collectible, x, y);
			else if (tile == 'E')
				draw_tile(game, game->img_exit_closed, x, y);
		x++;
		}	
		y++;
	}
}
void	draw_player(t_vars *game)
{
	ft_printf("player_x=%d, player_y=%d\n", game->player_x, game->player_y);
   ft_printf("img_player=%p\n", game->img_player);
	draw_tile(game, game->img_player, game->player_x, game->player_y);
}

void	update_window(t_vars *vars)
{
	ft_printf("[DEBUG] Entrou em update_window\n");
	draw_map(vars);
	draw_player(vars);
}

