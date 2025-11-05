/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:41:02 by lmanzani          #+#    #+#             */
/*   Updated: 2025/11/05 18:47:57 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include "../LIBFT/libft.h"

void	*load_image(void *mlx_ptr, char *path)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(mlx_ptr, path, &w, &h);
	if (!img)
		ft_printf("fail loading image: %s\n", path);
	return (img);
}

void	destroy_image(void *mlx_ptr, void *img)
{
	if (img)
		mlx_destroy_image(mlx_ptr, img);
}

int	load_all_images(t_vars *game)
{
	game->img_wall = load_image(game->mlx, "textures/wall.xpm");
	game->img_floor = load_image(game->mlx, "textures/floor.xpm");
	game->img_player = load_image(game->mlx, "textures/character.xpm");
	game->img_exit_open = load_image(game->mlx, "textures/open_door.xpm");
	game->img_exit_closed = load_image(game->mlx, "textures/closed_door.xpm");
	game->img_collectible = load_image(game->mlx, "textures/key.xpm");
	if (!game->img_wall || !game->img_floor || !game->img_player)
		return (0);
	if (!game->img_exit_open || !game->img_exit_closed ||!game->img_collectible)
		return (0);
	return (1);
}

void	destroy_all_images(t_vars *game)
{
	destroy_image(game->mlx, game->img_wall);
	destroy_image(game->mlx, game->img_floor);
	destroy_image(game->mlx, game->img_player);
	destroy_image(game->mlx, game->img_exit_closed);
	destroy_image(game->mlx, game->img_exit_open);
	destroy_image(game->mlx, game->img_collectible);
}
