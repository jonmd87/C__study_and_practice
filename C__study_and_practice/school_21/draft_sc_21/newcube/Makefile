# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/15 17:29:33 by lbardly           #+#    #+#              #
#    Updated: 2020/12/01 17:31:28 by lbardly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d 

CC = clang

DBG = -Wall -Wextra -Werror -g -fsanitize=address -Lmlx -lmlx -L./source/libft/ -lft

FLAGS = -Wall -Wextra -Werror -Lmlx -lmlx -framework OpenGL -framework AppKit -L./libft/ -lft
WALL = -Wall -Wextra -Werror -g -fsanitize=address


FRAMEWORK = -framework OpenGL -framework AppKit

PATH_S = ./source/

PATH_O = ./objects/

FUNC =	check_data_from_input_file.c \
		check_map.c \
		cub3d.c \
		distrib.c \
		exit_free.c \
		get_color.c \
		hit_rays.c \
		init.c \
		init2.c \
		make_picture.c \
		move_plr.c \
		open_file_close.c \
		parser_input_data.c \
		save_image.c \
		show_functions.c 

SRC = $(addprefix $(PATH_S), $(FUNC))

OBJ_T = $(patsubst %.c, %.o, $(FUNC))
OBJ = $(addprefix $(PATH_O), $(OBJ_T))

LIB_DIR = ./source/libft/
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
#	$(MAKE) clean -C $(LIB_DIR)
	@echo "\033[31m*******CUBE-->ALL OBJECTS FILES WAS DELETED*********\033[0m"

fclean: clean
	@rm -f $(NAME)
#	$(MAKE) fclean -C $(LIB_DIR)
	@echo "\033[31m************** [CUBE-->>>$(NAME)] DELETED************\033[0m"

re: fclean all

.PHONY: all clean fclean re CUB3D
