NAME = libft.a

CC= cc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = .

SRCS = $(SRC_DIR)/










































OBJS = $(SRCS:.c=.o)

all: $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(SRC_DIR) -c $< -o $@

clean: 
	rm -rf $(NAME)

re: fclean
	make

.PHONY: all celan fclean re bonus
