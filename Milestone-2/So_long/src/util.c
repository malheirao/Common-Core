#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include "../LIBFT/libft.h"

void collect_counter(t_vars *game)
{
	int verify;
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
					verify = 1;
				x++;
			}
		y++;	
		}
		if(game->total_collectibles ==0)
		{
		ft_printf("You must have at least one collectible");
		exit(1);
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

void general_parser(t_vars *game)
{
	check_players(game);
	check_exits(game);
	dimension_checker(game);
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
