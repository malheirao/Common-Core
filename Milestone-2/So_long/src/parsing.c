#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include "../LIBFT/libft.h"

void check_players(t_vars *game)
{
	int players;
	int x;
	int y;
	char tile;
	
	players = 0;
	y = 0;
		while(game->map[y])
		{
			x = 0;
			while(game-> map[y][x])
			{
				tile = game->map[y][x];
				if (tile == 'P')
					players++;
				x++;
			}
		y++;	
		}
		if (players != 1)
		{
			ft_printf("You can't have more than 1 player!.\n");
			exit(1);
		}	
}

void check_exits(t_vars *game)
{
	int exits;
	int x;
	int y;
	char tile;
	
	exits = 0;	
	y = 0;
		while(game->map[y])
		{
			x = 0;
			while(game-> map[y][x])
			{
				tile = game->map[y][x];
				if (tile == 'E')
					exits++;
				x++;
			}
		y++;	
		}
		if (exits != 1)
		{
			ft_printf("You can't have more than 1 exit!.\n");
			exit(1);
		}	
}

void dimension_checker(t_vars *game)
{
	if(game-> map_rows == game->map_columns)
	{
		ft_printf("The map must be rectangular!");
		exit(1);
	}
	else if (!game->map || !game->map[0])
	{
	ft_printf("You must submit a map!");
		exit(1);
	}
}
