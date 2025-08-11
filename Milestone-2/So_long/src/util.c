#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include "../LIBFT/libft.h"

void collect_counter(t_vars *game)
{
	int x;
	int y;
	char tile;


	game->total_collectibles = 0;
	y = 0;
		while(game->map[y])
		{
			x = 0;
			while(game-> map[y][x])
			{
				tile = game->map[y][x];
				if (tile == 'C')
					game->total_collectibles++;
				x++;
			}
		y++;	
		}	
}	

void finish_game(t_vars *game)
{
	int x;
	int y;
	char tile;
	
	y = 0;
		while(game->map[y])
		{
			x = 0;
			while(game-> map[y][x])
			{
				tile = game->map[y][x];
		if (game->map[game->player_y][game->player_x] == 'E')
					exit_game(game);
				x++;
			}
		y++;	
		}	
}

/*void move_counter(t_vars *game)
{
	int i;
	i = 0;

	if (move_right_or_left() || move_up_or_down())
	{
		i = i + 1;
		ft_printf("Move counter: %d", i);
	}
}*/
