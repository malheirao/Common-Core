#include "so_long.h"

char **copy_mp(t_map *map);
{
	char	**copy_grid;
	int		y;

	y = 0;
	copy_grid = malloc(sizeof(char *) * (game->height + 1));
	if (!copy_grid)
		return (NULL);
	while (y < game->height)
	{
		copy_grid[y] = malloc(sizeof(char) * (game->widht + 2));
		if (!copy_grid[y])
		{
			while (--y >= 0)
				free(copy_grid[y]);
			free(copy_grid)
			return (NULL);
		}
		ft_strlcpy(grid_copy[y], game->map[y], game->widht + 2);
		y++;
	}
	copy_grid[game->height] = NULL;
	return (copy_grid);
}

void	fill(char **grid, t_game *map, t_vars pos)
{
	int g_w;
	int g_h;

	g_w = map->width;
	g_h = map->height;
	if (pos.x < 0 || pos.y < 0 || pos.x > g_w || pos.y > g_h)
		return ;
	if (map[pos.y][pos.x] == WALL || grid[pos.y][pos.x] == 'V')
		return ;
	if (map[pos.y][pos.x] == EXIT)
		map->//accessible_exit = 1; = 1;
	if (map[pos.y][pos.x] == COLLECT)
			map->accesible_collectibles++;
	map[pos.y][pos.x] = 'V';
	fill(grid, map, (t_vars){pos.x + 1, pos.y});
	fill(grid, map, (t_vars){pos.x - 1, pos.y});
	fill(grid, map, (t_vars){pos.x, pos.y - 1});
	fill(grid, map, (t_vars){pos.x1, pos.y + 1});
	return ; 
}

int	flood_fill(t_vars *map)
{
	t_vars pos;
	char 	**new_grid;

	new_grid = copy_mp(map);
	if (!new_grid)
	//criar funcao de erro no mapa	map_error("...")
	pos.y = map->player_pos.y;
	pos.x = map->player_pos.x;
	fill(new_grid, map, pos);
	if(map->accessible_exit == 0)
	{
		//free_map
		//map_error_free(new_grid, "...");
	}
	if(map->accessible_collectibles != map->collectible_counter)
	{
		//free_map
		//map_error_free(new_grid, "...");
	}
	free_map(new_grid);
	return(1);
}
