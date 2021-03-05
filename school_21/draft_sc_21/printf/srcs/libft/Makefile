# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/02 19:25:16 by lbardly           #+#    #+#              #
#    Updated: 2020/07/26 19:37:54 by lbardly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
FUNC =	ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memccpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \

OBJ = $(patsubst %, %.o, $(FUNC))

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) 
	@ar rc $(NAME) $? 
	@echo "\033[32m********** -[$(NAME)]- was created ***********\033[0m"
	@ranlib $(NAME)
	@echo "\033[32m********** -[$(NAME)]- indexed ***********\033[0m"

%.o: %.c
	@gcc $(FLAG) -o $@ -c $?
	@echo "\033[34mLIBFT.........\033[0m\033[36m$@ - [$(FLAG)] - READY\033[0m"

.PHONY: clean
clean:
	@rm -f $(OBJ)
	@echo "\033[31m*******ALL OBJECTS FILES WAS DELETED*********\033[0m"
	
.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m**************$(NAME) DELETED************\033[0m"

.PHONY: re
re: fclean all
