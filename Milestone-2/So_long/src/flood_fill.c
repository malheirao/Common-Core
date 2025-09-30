#include "so_long.h"

static char **copy_map(char **map, int rows)
{
	char **copy;
	int y;

	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < rows)
	{
		copy[y] = ft_strdup(map[y]);
		if(!copy[y])
		{
			int j = 0;
			while (j < y)
				free(copy[j++]);
			free(copy);
			return NULL;
		}
		y++;
	}
	copy[rows] = NULL;
	return (copy);
}

static void fill(char **grid, int x, int y, int *collect, int *exit)
{
	if(y < 0 || grid[y] == NULL)
		return;
	if (x < 0 || x >= (int)ft_strlen(grid[y]))
		return;
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return;
	if (grid[y][x] == 'E')
		(*exit)++;
	if (grid[y][x] == 'C')
		(*collect)++;
	grid[y][x] = 'V';
	fill(grid, x + 1, y, collect, exit);
	fill(grid, x - 1, y, collect, exit);
	fill(grid, x, y + 1, collect, exit);
	fill(grid, x, y - 1, collect, exit);
	return ; 
}

int	flood_fill(t_vars *game)
{
	int found_collect;
	int found_exit;
	char **map_copy;

	found_collect = 0;
	found_exit = 0;
	map_copy = copy_map(game->map, game->map_rows);
	if(!map_copy)
		return (0);
	fill(map_copy, game->player_x, game->player_y, &found_collect, &found_exit);
	ft_printf("DEBUG: Achei %d%d colecionaveis, %d saída(s)\n", found_collect, game->total_collectibles, found_exit);
	free_map(map_copy);
	if (found_collect == game->total_collectibles && found_exit > 0)
		return (1);
	return (0);
}
