# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 17:19:16 by asirenko          #+#    #+#              #
#    Updated: 2019/03/24 18:14:12 by asirenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_DIR = ./src/
OBJ_DIR = ./
INC_DIR = ./inc/
LIB_DIR = ./lib/

SRC = main.c keys.c get_next_line.c reader.c keys2.c calc.c draw.c init.c \
	textures.c validate.c validate2.c keys3.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC = gcc -Wall -Wextra -Werror -O2

FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = $(LIB_DIR)libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@$(CC) $(LIBFT) $(OBJ) $(FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ -I $(INC_DIR)

clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
