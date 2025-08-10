#include "../minilibx-linux/mlx.h"



int main(void)
{

	int w;
	int h;

	void *mlx_connection;
	void *mlx_window;
	void *img;

	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, 1920, 1080, "test");

	void *image_wall = mlx_xpm_file_to_image(mlx_connection, "./textures/wall.xpm", &w, &h);
	void *image_floor = mlx_xpm_file_to_image(mlx_connection, "./textures/floor.xpm", &w, &h);
	
	mlx_put_image_to_window(mlx_connection, mlx_window, image_wall, 0, 0);
	mlx_put_image_to_window(mlx_connection, mlx_window, image_floor, 64, 0);
	
	mlx_loop(mlx_connection);
}
