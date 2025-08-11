#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include "../LIBFT/libft.h"

int main(int argc, char **argv)
{
    t_vars vars;

    if (argc != 2)
    {
        printf("Uso: %s <mapa.ber>\n", argv[0]);
        return (1);
    }

    vars.mlx = mlx_init();
    if (!vars.mlx)
        return (1);

    // Carregue o mapa a partir do argumento da linha de comando
    vars.map = load_map(argv[1]);
    if (!load_map(argv[1]))
    {
        printf("Erro ao carregar o mapa: %s\n", argv[1]);
        return (1);
    }

    // Crie a janela do tamanho do mapa
    int width = vars.map_columns * 32;
    int height = vars.map_rows * 32;
    vars.win = mlx_new_window(vars.mlx, width, height, "so_long");
    if (!vars.win)
        return (1);

    // Carregue as imagens (adicione sua função de load_images se tiver)
    // load_all_images(&vars);

    // Desenha o mapa inicial
    update_window(&vars);

    // Loop principal da MLX
    mlx_loop(vars.mlx);

    return (0);
}
