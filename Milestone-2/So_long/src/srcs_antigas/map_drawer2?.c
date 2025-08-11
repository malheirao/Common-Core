#include "../LIBFT/libft.h"
#include "../includes/so_long.h"
#include <stdio.h>
#include "../minilibx-linux/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h> 

#define TILE_SIZE 32

int main(int ac, char **av)
{
	if (ac == 2)
	{
		void	*mlx_connection;
		void	*mlx_window;
		void	*image_wall;
		void	*image_floor;
		int		img_w;
		int		img_h;
		int		window_width;
		int		window_height;
		int		offset_x;
		int		offset_y;
		int		map_columns;
		int		map_rows;
		int		x;
		int		y;
		char	**map;


		map = load_map(av[1]);
		if (!map)
		{
			ft_printf("Erro ao carregar o mapa!\n");
			return (1);
		}
		map_rows = 0;
		while (map[map_rows])
			map_rows++;
		map_columns = 0;
		while (map[0][map_columns])
			map_columns++;
		window_width = map_columns * TILE_SIZE;
		window_height = map_rows * TILE_SIZE;
		mlx_connection = mlx_init();
		mlx_window = mlx_new_window(mlx_connection, window_width, window_height, "Meu Jogo");
		image_wall = mlx_xpm_file_to_image(mlx_connection, "../textures/wall.xpm", &img_w, &img_h);
		image_floor = mlx_xpm_file_to_image(mlx_connection, "../textures/floor.xpm", &img_w, &img_h);
		
		void *image_collectible = mlx_xpm_file_to_image(mlx_connection, "../textures/collectible.xpm", &img_w, &img_h);
		if (!image_collectible)
		{
			ft_printf("Erro ao carregar imagem do colecionável\n");
			// Trate o erro ou encerre
		}
		offset_x = (window_width - (map_columns * TILE_SIZE)) / 2;
		offset_y = (window_height - (map_rows * TILE_SIZE)) / 2;

		y = 0;
		while (y < map_rows)
		{
			x = 0;
		while (x < map_columns)
		{
			char tile = map[y][x];
			mlx_put_image_to_window(mlx_connection, mlx_window, image_floor,
				offset_x + x * TILE_SIZE, offset_y + y * TILE_SIZE);
			if (tile == '1')
				mlx_put_image_to_window(mlx_connection, mlx_window, image_wall,
					offset_x + x * TILE_SIZE, offset_y + y * TILE_SIZE);
			x++;
		}
		y++;
		}
		void *image_player;
		image_player = load_player_img(mlx_connection);
		if(!image_player)
		{
			ft_printf("erro ao carregar player.xpm\n");
			return(1);
		}
		if (ac == 2)
		{
			int player_x;
			int player_y;
	
			player_pos(map, &player_x, &player_y);
			ft_printf("player em: %d, %d\n", player_x, player_y);
			mlx_put_image_to_window(mlx_connection, mlx_window, image_player,
			offset_x + player_x * TILE_SIZE, offset_y + player_y * TILE_SIZE);
		}
		mlx_loop(mlx_connection);
		free_map(map);
		return (0);
}
}
