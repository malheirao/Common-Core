#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include "../LIBFT/libft.h"

#define TILE_SIZE 32

static int	init_vars(t_vars *vars, char *map_path)
{
	ft_memset(vars, 0, sizeof(t_vars));
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (ft_printf("Erro ao inicializar MiniLibX!\n"), 0);
	vars->map = load_map(map_path);
	if (!vars->map)
		return (ft_printf("Erro ao carregar o mapa: %s\n", map_path), 0);
	//free map ^
	//if (!vars->map[0])
	//		return (ft_printf("You can not submit an empty map."));
	vars->map_rows = 0;
	while (vars->map[vars->map_rows])
		vars->map_rows++;
	vars->map_columns = ft_strlen(vars->map[0]);
	return (1);
}

static int	create_window_and_images(t_vars *vars)
{
	int	width = vars->map_columns * TILE_SIZE;
	int	height = vars->map_rows * TILE_SIZE;

	vars->win = mlx_new_window(vars->mlx, width, height, "so_long");
	if (!vars->win)
	{
		ft_printf("Erro ao criar a janela!\n");
		free_map(vars->map, vars->map_rows);
		return (0);
	}
	if (!load_all_images(vars))
	{
		ft_printf("Erro ao carregar imagens!\n");
		destroy_all_images(vars);
		free_map(vars->map, vars->map_rows);
		return (0);
	}
	return (1);
}

static int	init_game_state(t_vars *vars)
{
	player_pos(vars->map, &vars->player_x, &vars->player_y);
	if (vars->player_x < 0 || vars->player_y < 0)
	{
		//printf("Erro: posição do jogador não encontrada!\n");
		destroy_all_images(vars);
		free_map(vars->map, vars->map_rows);
		return (0);
	}
	collect_counter(vars);
	vars->move_count = 0;
	vars->collected = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (printf("Uso: %s <mapa.ber>\n", argv[0]), 1);
	if (!init_vars(&vars, argv[1]))
		return (1);
	//if (!check_map_rectangular(&vars))
	//	return (1);
	general_parser(&vars);
	if (!is_map_valid(&vars))
	{	
		exit_game(&vars);
		ft_printf("The map is not valid \n");
	}
	//else
	//	ft_printf("INVALID MAP");
	if (!create_window_and_images(&vars))
		return (1);
	if (!init_game_state(&vars))
		return (1);
	mlx_key_hook(vars.win, key_handler, &vars);
	update_window(&vars);
	mlx_loop(vars.mlx);

	exit_game(&vars);
	//destroy_all_images(&vars);
	//free_map(vars.map, vars.map_rows);
	return (0);
}
