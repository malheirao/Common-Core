NAME = so_long

MLX_PATH = minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

LIBFT_PATH = LIBFT
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBFT_INC = $(LIBFT_PATH)
LIBFT_FLAGS = -I$(LIBFT_INC)

SRC = src/main.c \
      src/map.c \
      src/drawer.c \
      src/util.c \
      src/movement.c \
      src/events.c \
      src/image.c \
      src/parsing.c \
      src/flood_fill.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes -I$(MLX_PATH) $(LIBFT_FLAGS)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft $(MLX_FLAGS) -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX_LIB):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		git clone $(MLX_REPO) $(MLX_PATH); \
	fi
	$(MAKE) -C $(MLX_PATH)

$(OBJ): $(MLX_LIB)

src/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) clean || true
	@if [ -d "$(MLX_PATH)" ]; then $(MAKE) -C $(MLX_PATH) clean 2>/dev/null || true; fi
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean || true
	rm -rf $(MLX_PATH)
	rm -f $(NAME)

re: fclean all
