# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/15 17:29:33 by lbardly           #+#    #+#              #
#    Updated: 2020/10/29 22:03:19 by lbardly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d 

CC = clang

DBG = -Wall -Wextra -Werror -g -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit -L./libft/ -lft

FLAGS = -Wall -Wextra -Werror -Lmlx -lmlx -framework OpenGL -framework AppKit -L./libft/ -lft
WALL = -Wall -Wextra -Werror -g -fsanitize=address


FRAMEWORK = -framework OpenGL -framework AppKit

PATH_S = ./srcs/

PATH_O = ./objects/

FUNC =	checks_input_file_data.c \
		checks_mlx_data.c \
		checks_resived_data.c \
		cub3d.c \
		exit.c \
		get_data.c \
		get_next_line.c \
		init.c \
		init2.c \
		init_utils.c \
		parser.c \
		start_mlx.c \
		DEL_AFTER_show_data.c

SRC = $(addprefix $(PATH_S), $(FUNC))

OBJ_T = $(patsubst %.c, %.o, $(FUNC))
OBJ = $(addprefix $(PATH_O), $(OBJ_T))

LIB_DIR = ./libft/
LIB = libft.a
LIBA = $(addprefix $(LIB_DIR), $(LIB))
LIB_HEAD = $(addprefix $(LIB_DIR), libft.h)

all: $(LIB) $(NAME)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJ)
	$(CC) $(DBG) $(OBJ) -o $(NAME) 

$(PATH_O)%.o: $(PATH_S)%.c
	$(CC) $(WALL) -o $@ -c $<

clean:
	rm -rf $(OBJ)
#	$(MAKE) clean -C $(LIB_DIR)     												УДАЛИ # !!!!!
	@echo "\033[31m*******CUBE-->ALL OBJECTS FILES WAS DELETED*********\033[0m"

fclean: clean
	@rm -f $(NAME)
#	$(MAKE) fclean -C $(LIB_DIR)													УДАЛИ # !!!!!
	@echo "\033[31m************** [CUBE-->>>$(NAME)] DELETED************\033[0m"

re: fclean all
	./Cub3d ./maps/map1.cub

.PHONY: all clean fclean re CUB3D
