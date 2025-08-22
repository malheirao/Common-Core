NAME = so_long

# Diretório da MinilibX
MLX_PATH = minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_FLAGS = $(MLX_LIB) -lXext -lX11 -lm -lz

# Diretório da LIBFT
LIBFT_PATH = LIBFT
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -I$(LIBFT_PATH)

SRC = src/main.c \
      src/map.c \
      src/drawer.c \
      src/util.c \
      src/movement.c \
      src/events.c \
      src/image.c \
      src/parsing.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_LIB) -o $(NAME)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -Iincludes -I$(MLX_PATH) $(LIBFT_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
