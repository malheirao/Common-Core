//#include <stdio.h>
//#include <stddef.h>
//#include "../minilibx-linux/mlx.h"
//#define TILE_SIZE 32
/*
int main()
{
    void *mlx_connection;
    void *mlx_window;
    void *image_wall;
    void *image_floor;
    int img_w;
    int img_h;
    int	window_width;
    int	window_height;
    
    window_width = map_columns * TILE_SIZE;
    window_height = map_rows * TILE_SIZE;

    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, window_width, window_height, "Meu Jogo");



    // Carrega as imagens
    image_wall = mlx_xpm_file_to_image(mlx_connection, "../textures/wall.xpm", &img_w, &img_h);
    image_floor = mlx_xpm_file_to_image(mlx_connection, "../textures/floor.xpm", &img_w, &img_h);

    // Mapa exemplo
    char *map[] = {
        "11111",
        "1P0C1",
        "100E1",
        "11111",
        NULL
    };

    // Percorre o mapa e desenha as imagens
    /*for (int y = 0; map[y] != NULL; y++)
    {
        for (int x = 0; map[y][x] != '\0'; x++)
        {
            char tile = map[y][x];
            if (tile == '1')
                mlx_put_image_to_window(mlx_connection, mlx_window, image_wall, x * TILE_SIZE, y * TILE_SIZE);
                mlx_put_image_to_window(mlx_connection, mlx_window, image_floor, x * TILE_SIZE, y * TILE_SIZE);
            else if (tile == '0')
            // Adicione outros tipos aqui (player, coletável etc)
        }
    }*/
    
    
/*    int offset_x;
    int offset_y;
    
    offset_x = (window_width - (map_columns * TILE_SIZE)) / 2;
    offset_y = (window_height - (map_rows * TILE_SIZE)) / 2;
    
    
    
    for (int y = 0; map[y] != NULL; y++)
{
    for (int x = 0; map[y][x] != '\0'; x++)
    {
        char tile = map[y][x];
        // Sempre desenhe o chão primeiro!
        mlx_put_image_to_window(mlx_connection, mlx_window, image_floor, x * TILE_SIZE, y * TILE_SIZE);

        // Depois desenhe o que for por cima
        if (tile == '1')
            mlx_put_image_to_window(mlx_connection, mlx_window, image_wall, x * TILE_SIZE, y * TILE_SIZE);
       // else if (tile == 'P')
//            mlx_put_image_to_window(mlx_connection, mlx_window, image_player, x * TILE_SIZE, y * TILE_SIZE);
       // else if (tile == 'C')
  //          mlx_put_image_to_window(mlx_connection, mlx_window, image_collectible, x * TILE_SIZE, y * TILE_SIZE);
     //   else if (tile == 'E')
    //        mlx_put_image_to_window(mlx_connection, mlx_window, image_exit, x * TILE_SIZE, y * TILE_SIZE);
    }
}

    mlx_loop(mlx_connection);
    return 0;
}*/

CODIGO PAUSADO NO MOMENTO
