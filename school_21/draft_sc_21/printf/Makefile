# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 08:46:09 by lbardly           #+#    #+#              #
#    Updated: 2020/08/06 06:14:50 by lbardly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FUNC =  ft_distribution \
		ft_get_cell \
		ft_get_specificators \
		ft_print_utils \
		ft_printf \
		ft_show_adres \
		ft_show_char \
		ft_show_data_utils \
		ft_show_integ \
		ft_show_string \
		ft_show_unsig \

FLAG = -Wall -Wextra -Werror

LIB_DIR = ./srcs/libft/
LIB = libft.a
LIBA = $(addprefix $(LIB_DIR), $(LIB))
LIB_HEAD = $(addprefix $(LIB_DIR), libft.h)

SRC_DIR = ./srcs/
SRC_FILES = $(FUNC:=.c) 
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
HEADER =  ./ft_printf.h

OBJ_DIR = ./objects/
OBJ = $(patsubst %, %.o, $(FUNC))

all: $(LIB) $(NAME)

$(NAME): $(OBJ) 
	@cp $(LIBA) ./$(NAME)
	@ar rc $(NAME) $?
	@echo "\033[32m********** -[$(NAME)]- was created ***********\033[0m"
	@ranlib $(NAME)
	@echo "\033[32m********** -[$(NAME)]- indexed ***********\033[0m"	

%.o: $(SRC_DIR)%.c 
	@gcc $(FLAG) -o $@ -c $<  
	@echo "\033[34mPRINTF........\033[0m\033[36m$@ [$(FLAG)] -- READY \033[0m"

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(MAKE) clean -C $(LIB_DIR)
	@rm -rf $(OBJ)
	@echo "\033[31m*******ALL OBJECTS FILES WAS DELETED*********\033[0m"

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	@rm -f $(NAME)
	@echo "\033[31m**************$(NAME) DELETED************\033[0m"

re: fclean all

.PHONY: all clean fclean re
