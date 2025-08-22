NAME = so_long

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_FLAGS = $(MLX_LIB) -lXext -lX11 -lm -lz

SRC = src/main.c \
      src/map.c \
      src/drawer.c \
      src/util.c \
      src/movement.c \
      src/events.c \
      src/image.c \

OBJ = $(SRC:.c=.o)

CC =  cc
 
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
