# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 17:49:56 by lmanzani          #+#    #+#              #
#    Updated: 2025/07/04 17:50:26 by lmanzani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

BONUS_NAME = server_bonus
BONUS_NAME2 = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_SRCS = ft_printf.c ft_printfutilis.c ft_printfutilis2.c
SRC_CLIENT = client.c utils.c ft_atoi.c $(FT_PRINTF_SRCS)
SRC_SERVER = server.c utils.c $(FT_PRINTF_SRCS)

BONUS_SRCS = server_bonus.c utils.c ft_atoi.c $(FT_PRINTF_SRCS)
BONUS_SRCS2 = client_bonus.c utils.c ft_atoi.c $(FT_PRINTF_SRCS)

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

bonus: $(BONUS_NAME) $(BONUS_NAME2)

$(BONUS_NAME): $(BONUS_SRCS)
				$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_SRCS)
$(BONUS_NAME2): $(BONUS_SRCS2)
				$(CC) $(CFLAGS) -o $(BONUS_NAME2) $(BONUS_SRCS2)
clean:
			rm -f *.o

fclean: clean
			rm -f $(NAME_CLIENT) $(NAME_SERVER) $(BONUS_NAME) $(BONUS_NAME2)

re: fclean all

.PHONY: all bonus clean fclean re
