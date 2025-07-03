NAME_CLIENT = consultant
NAME_SERVER = oracule

CC = cc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_SRCS = ft_printf.c ft_printfutilis.c ft_printfutilis2.c
SRC_CLIENT = consultant.c utils.c $(FT_PRINTF_SRCS)
SRC_SERVER = oracule.c utils.c $(FT_PRINTF_SRCS)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

HEADER = talk.h ft_printf.h

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
				$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
				$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
