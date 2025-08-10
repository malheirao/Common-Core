#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_game
{
	char **map;
	int width;
	int height;
	int n_collect;
	int n_player;
	int n_exit;
} t_game;

typedef struct s_vars
{
	void *mlx;
	void *win;
	void *img_floor;
	void *img_wall;
	void *img_player;
	void *img_exit_closed;
	void *img_exit_open;
	void *img_collectible;
	char **map;
	int player_x;
	int player_y;
	int map_rows;
	int map_columns;
	int collected;
	int total_collectibles;
} t_vars;

// Função que lê o mapa de um arquivo e retorna um array de strings (char **)
char	**load_map(const char *filename);

// Função que libera toda a memória de um mapa carregado
void	free_map(char **map);

void	player_pos(char **map, int *x, int *y);
void	*load_player_img(void *mlx);
void	draw_player(void *mlx, void *win, void *img, int x, int y);

int		keypress(int keycode, t_vars *vars);
void	general_drawer(t_vars *vars);

#endif
