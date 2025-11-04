#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include "../LIBFT/libft.h"

void fill (char **tab, int rows, int cols, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= rows || col >= cols)
		return;
	if (tab[row][col] == 'F') 
		return;
	if (tab[row][col] != target && tab[row][col] != 'C' && tab[row][col] != 'E')
		return;
	tab[row][col] = 'F';
	fill(tab, rows, cols, target, row, col + 1);
	fill(tab, rows, cols, target, row, col - 1);
	fill(tab, rows, cols, target, row + 1, col);
	fill(tab, rows, cols, target, row - 1, col);
}

void flood_fill(t_vars *game)
{
	char target;
	target = game->map[game->player_y][game->player_x];
	fill(game->map, game->map_rows, game->map_columns, target, game->player_y, game->player_x);
}
	
char **dup_map(char **original, int rows, int cols)
{
    char **copy = malloc(sizeof(char *) * (rows + 1));
    if (!copy)
        return NULL;
    
    int i = 0;
    while (i < rows)
    {
        copy[i] = malloc(cols + 1);
        if (!copy[i])
        {
            int j = 0;
            while (j < i)
                free(copy[j++]);
            free(copy);
            return NULL;
        }
        
        int j = 0;
        while (j < cols)
        {
            copy[i][j] = original[i][j];
            j++;
        }
        copy[i][j] = '\0';
        i++;
    }
    copy[rows] = NULL;
    return copy;
}



/*{
    char **copy = malloc(sizeof(char *) * rows + 1);
    int i = 0;
    while (i < rows)
    {
        int j = 0;
        copy[i] = malloc(cols + 1);
        while (j < cols)
        {
            copy[i][j] = original[i][j];
            j++;
        }
        copy[i][j] = '\0';
        i++;
	ft_printf("VALIDOU DUP MAP");
    }
    return copy;
}*/
