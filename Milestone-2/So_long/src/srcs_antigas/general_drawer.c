#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

#define TILE_SIZE 32

void general_drawer(t_vars *vars)
{
	int x;
	int y;

	for (y = 0; y < vars->map_rows; y++)
	{
		for (x = 0; x < vars -> map_columns; x++)
		{
			char tile;

			tile = vars->map[y][x];
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor, 
									x * TILE_SIZE, y * TILE_SIZE);
			if (tile == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_wall,
									x * TILE_SIZE, y *TILE_SIZE);
			else if (tile == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_collectible,
									x * TILE_SIZE, y *TILE_SIZE);
			else if (tile == 'E')
			{
				if (vars->collected == vars->total_collectibles)	
					mlx_put_image_to_window(vars->mlx, vars->win, vars->img_exit_open,
									    x * TILE_SIZE, y *TILE_SIZE);
				else	
					mlx_put_image_to_window(vars->mlx, vars->win, vars->img_exit_closed,
									    x * TILE_SIZE, y *TILE_SIZE);
			}
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player, vars->player_x * TILE_SIZE, vars->player_y * TILE_SIZE);
}
