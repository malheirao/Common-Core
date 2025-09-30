#ifndef SO_LONG_H
#define SO_LONG_H

#define KEY_UP	65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363

#define KEY_ESC 65307

#include <stdlib.h>
#include "../LIBFT/libft.h"

typedef struct s_point
{
	int x;
	int y;
} t_point;


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
	char tile;
	int exit_open;
	int player_x;
	int player_y;
	int map_rows;
	int map_columns;
	int collected;
	int total_collectibles;
	int move_count;
	int verify;
} t_vars;

// Função que lê o mapa de um arquivo e retorna um array de strings (char **)
char	**load_map(const char *filename);

// Função que libera toda a memória de um mapa carregado
void	free_map(char **map);

void	player_pos(char **map, int *x, int *y);
void	*load_player_img(void *mlx);

int	keypress(int keycode, t_vars *vars);
void	general_drawer(t_vars *vars);
int	count_collec(char **map);
//images.c
void    *load_image(void *mlx_ptr, char *path);
void    destroy_image(void *mlx_ptr, void *img);
int     load_all_images(t_vars *game);
void    destroy_all_images(t_vars *game);

//drawer.c
void	draw_tile(t_vars *game, void *img, int x, int y);
void	draw_map(t_vars *vars);
void	draw_player(t_vars *vars);
void	update_window(t_vars *vars);

//movement.c
int key_handler(int keycode, t_vars *game);
void move_up_or_down(t_vars *game, int direction);
void move_right_or_left(t_vars *game, int direction);
int exit_game(t_vars *game);

//events.c
void collect(t_vars *game);
void total_collected(t_vars *game);

//utils.c
void collect_counter(t_vars *game);
void finish_game(t_vars *game);
void general_parser(t_vars *game);

//parsing.c
void dimension_checker(t_vars *game);
void check_exits(t_vars *game);
void check_players(t_vars *game);
void random_char_verify(t_vars *game);

// flood_fill.c
int     flood_fill(t_vars *game);
char    **copy_mp(t_vars *map);

#endif
