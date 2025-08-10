#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

#define TILE_SIZE 32

void	player_pos(char **map, int *x, int *y)
{
	int i;
	int j;

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
				return;
			}
			j++;
		}
		i++;
	}
	*x = -1;
	*y = -1;
}

void *load_player_img(void *mlx)
{
	int w;
	int h;

	return mlx_xpm_file_to_image(mlx, "../textures/character.xpm", &w, &h);
}
void	draw_player(void *mlx, void *win, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx, win, img, x * TILE_SIZE, y * TILE_SIZE);
}
