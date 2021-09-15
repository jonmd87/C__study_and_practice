# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/02 19:25:16 by lbardly           #+#    #+#              #
#    Updated: 2020/08/15 23:03:16 by lbardly          ###   ########.fr        #
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

BONUS = ft_lstadd_back \
		ft_lstadd_front \
		ft_lstclear \
		ft_lstdelone \
		ft_lstiter \
		ft_lstlast \
		ft_lstmap \
		ft_lstnew \
		ft_lstsize \
			ft_clean_mem \

OBJ = $(patsubst %, %.o, $(FUNC))
SRC = $(patsubst %, %.c, $(FUNC))

BONUS_OBJ = $(patsubst %, %.o, $(BONUS))
BONUS_SRC = $(patsubst %, %.c, $(BONUS))

.PHONY: all

all: $(NAME)

bonus: $(BONUS_OBJ)
	@ar rc $(NAME) $? 
	@echo "\033[32m********** -[$(NAME)]- was created ***********\033[0m"
	@ranlib $(NAME)
	@echo "\033[32m********** -[$(NAME)]- indexed ***********\033[0m"

$(BONUS_OBJ): $(SRC) $(BONUS_SRC) 
	@gcc $(FLAG) -c $?
	@echo "\033[34mOBJECTS FILES WITH BONUS WAS CREATED \033[0m\033[36m - [$(FLAG)] - READY\033[0m"

$(NAME): $(OBJ) 
	@ar rc $(NAME) $? 
	@echo "\033[32m********** -[$(NAME)]- was created ***********\033[0m"
	@ranlib $(NAME)
	@echo "\033[32m********** -[$(NAME)]- indexed ***********\033[0m"

$(OBJ): $(SRC)
	@gcc $(FLAG) -c $?
	@echo "\033[34mOBJECTS FILES WAS CREATED \033[0m\033[36m - [$(FLAG)] - READY\033[0m"

.PHONY: clean
clean:
	@rm -f $(OBJ)
	@rm -f $(BONUS_OBJ)
	@echo "\033[31m*******ALL OBJECTS FILES WAS DELETED*********\033[0m"
	
.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m**************$(NAME) DELETED************\033[0m"

.PHONY: re
re: fclean all
