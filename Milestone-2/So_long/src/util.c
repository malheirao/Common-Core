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
				{
					game->total_collectibles++;
				game->verify = 1;
				}
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
	
	y = 0;
		while(game->map[y])
		{
			x = 0;
			while(game-> map[y][x])
			{
			game->tile = game->map[y][x];
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
	random_char_verify(game);
<<<<<<< HEAD
	if (!flood_fill(game))
	{
		ft_printf("Erro: caminho impossível!\n");
		free_map(game->map);
		exit(1);
	}
=======
	//is_map_valid(game);
	//if (!is_map_valid(game))
	//{	exit_game(game);
	//	ft_printf("VALIDOU");
	//}
	//else
	//	ft_printf("INVALID MAP");
	

}

int is_map_valid(t_vars *game)
{
	printf("Chamando fill em row=%d col=%d\n", game->player_y, game->player_x);
    char **map_copy = dup_map(game->map, game->map_rows, game->map_columns);
    if (!map_copy)
        return 0; 
    printf("COPIA FEITA\n");
    //flood_fill(game);
    fill(map_copy, game->map_rows, game->map_columns, '0', game->player_y, game->player_x);
    int valid = 1;
    int y = 0;
    while (y < game->map_rows)
    {
        int x = 0;
        while (x < game->map_columns)
        {
            if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
                valid = 0;
            x++;
        }
        y++;
    }

    free_map(map_copy, game->map_rows);
    return valid;
>>>>>>> 9aed318 (new changes)
}
