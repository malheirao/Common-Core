#include "../includes/so_long.h"
#include "../LIBFT/libft.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (ft_printf("Uso: %s <mapa.ber>\n", argv[0]), 1);
	vars.map = load_map(argv[1]);
	if (!vars.map)
		return (ft_printf("Erro ao carregar mapa\n"), 1);

	vars.map_rows = 0;
	while (vars.map[vars.map_rows])
		vars.map_rows++;
	vars.map_columns = ft_strlen(vars.map[0]);
	collect_counter(&vars);
	player_pos(vars.map, &vars.player_x, &vars.player_y);
	general_parser(&vars);

	//if (!create_window_and_images(&vars) || !init_game_state(&vars))
	//	return (ft_printf("Erro ao iniciar jogo\n"), free_map(vars.map), 1);
	mlx_key_hook(vars.win, key_handler, &vars);
	update_window(&vars);
	mlx_loop(vars.mlx);
	destroy_all_images(&vars);
	free_map(vars.map);
	return (0);
}
