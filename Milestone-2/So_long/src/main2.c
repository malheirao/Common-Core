#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include "../LIBFT/libft.h"

#define MAX_WIDTH 1920
#define MAX_HEIGHT 1080
#define TILE_SIZE 32

int main(int argc, char **argv)
{
    t_vars vars;
    int width, height;

    if (argc != 2)
    {
        printf("Uso: %s <mapa.ber>\n", argv[0]);
        return (1);
    }

    vars.mlx = mlx_init();
    if (!vars.mlx)
    {
        printf("Erro ao inicializar MiniLibX!\n");
        return (1);
    }

    vars.map = load_map(argv[1]);
    if (!vars.map)
    {
        printf("Erro ao carregar o mapa: %s\n", argv[1]);
        return (1);
    }

    // Calcula dimensões do mapa
    vars.map_rows = 0;
    while (vars.map[vars.map_rows])
        vars.map_rows++;
    vars.map_columns = ft_strlen(vars.map[0]);

    // Checa se todas as linhas têm o mesmo tamanho
    for (int i = 0; vars.map[i]; i++)
    {
        if ((int)ft_strlen(vars.map[i]) != vars.map_columns)
        {
            printf("Erro: linha %d do mapa tem tamanho diferente!\n", i);
            free_map(vars.map);
            return (1);
        }
    }

    width = vars.map_columns * TILE_SIZE;
    height = vars.map_rows * TILE_SIZE;
    printf("[DEBUG] width=%d, height=%d\n", width, height);

    if (width > MAX_WIDTH || height > MAX_HEIGHT)
    {
        printf("Erro: Mapa muito grande para a tela (%dx%d)!\n", width, height);
        free_map(vars.map);
        return (1);
    }

    vars.win = mlx_new_window(vars.mlx, width, height, "so_long");
    if (!vars.win)
    {
        printf("Erro ao criar a janela!\n");
        free_map(vars.map);
        return (1);
    }
    mlx_key_hook(vars.win, key_handler, &vars);


    if (!load_all_images(&vars))
    {
        printf("Erro ao carregar imagens!\n");
        destroy_all_images(&vars);
        free_map(vars.map);
        return (1);
    }

    player_pos(vars.map, &vars.player_x, &vars.player_y);
    if (vars.player_x < 0 || vars.player_y < 0)
    {
        printf("Erro: posição do jogador não encontrada!\n");
        destroy_all_images(&vars);
        free_map(vars.map);
        return (1);
    }

    // Desenha o mapa inicial
    update_window(&vars);

    // Loop principal da MLX
    mlx_loop(vars.mlx);

    // Cleanup (nunca será chamado, mas é boa prática)
    destroy_all_images(&vars);
    free_map(vars.map);

    return (0);
}
