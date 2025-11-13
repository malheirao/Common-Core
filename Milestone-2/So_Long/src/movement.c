/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:51:55 by lmanzani          #+#    #+#             */
/*   Updated: 2025/11/05 19:41:50 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include "../LIBFT/libft.h"

int	key_handler(int keycode, t_vars *game)
{
	if (keycode == KEY_LEFT)
		move_right_or_left(game, -1);
	else if (keycode == KEY_UP)
		move_up_or_down(game, -1);
	else if (keycode == KEY_DOWN)
		move_up_or_down(game, 1);
	else if (keycode == KEY_RIGHT)
		move_right_or_left(game, 1);
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}

void	move_right_or_left(t_vars *game, int direction)
{
	int	y;
	int	new_x;

	y = game->player_y;
	new_x = game-> player_x + direction;
	if (game->map[y][new_x] != '1')
	{
		game->player_x = new_x;
		collect(game);
		finish_game(game);
		update_window(game);
		ft_printf("Movements: %d\n", ++game->move_count);
	}
}

void	move_up_or_down(t_vars *game, int direction)
{
	int	x;
	int	new_y;

	x = game->player_x;
	new_y = game-> player_y + direction;
	if (game->map[new_y][x] != '1')
	{
		game->player_y = new_y;
		collect(game);
		finish_game(game);
		update_window(game);
		ft_printf("Movements: %d\n", ++game->move_count);
	}
}

int	exit_game(t_vars *game)
{
	destroy_all_images(game);
	free_map(game->map, game->map_rows);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
