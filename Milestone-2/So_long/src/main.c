/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:37:40 by lmanzani          #+#    #+#             */
/*   Updated: 2025/11/07 19:01:43 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include "../LIBFT/libft.h"

#define TILE_SIZE 32

static int	init_vars(t_vars *vars, char *map_path)
{
	ft_memset(vars, 0, sizeof(t_vars));
	vars->map = load_map(map_path);
	if (!vars->map || !vars->map[0])
		return (ft_printf("Error: empty or invalid map!\n"), 0);
	vars->map_rows = 0;
	while (vars->map[vars->map_rows])
		vars->map_rows++;
	vars->map_columns = ft_strlen(vars->map[0]);
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		free_map(vars->map, vars->map_rows);
		return (ft_printf("Erro ao inicializar MiniLibX!\n"), 0);
	}
	return (1);
}

static int	create_window_and_images(t_vars *vars)
{
	int	width;
	int	height;

	width = vars->map_columns * TILE_SIZE;
	height = vars->map_rows * TILE_SIZE;
	if (!load_all_images(vars))
	{
		ft_printf("Error loading images!\n");
		destroy_all_images(vars);
		free_map(vars->map, vars->map_rows);
		//exit_game(vars);
		return (0);
	}
	vars->win = mlx_new_window(vars->mlx, width, height, "so_long");
	if (!vars->win)
	{
		ft_printf("Error creating window!\n");
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
		ft_printf("Error: player not found!\n");
		destroy_all_images(vars);
		free_map(vars->map, vars->map_rows);
		mlx_destroy_window(vars->mlx, vars->win);
		return (0);
	}
	collect_counter(vars);
	vars->move_count = 0;
	vars->collected = 0;
	return (1);
}

int	close_window(t_vars *vars)
{
	exit_game(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (printf("Use: %s <mapa.ber>\n", argv[0]), 1);
	if (!init_vars(&vars, argv[1]))
		return (1);
	general_parser(&vars);
	if (!create_window_and_images(&vars))
		return (1);
	if (!init_game_state(&vars))
		return (1);
	mlx_key_hook(vars.win, key_handler, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	update_window(&vars);
	mlx_loop(vars.mlx);
	exit_game(&vars);
	return (0);
}
