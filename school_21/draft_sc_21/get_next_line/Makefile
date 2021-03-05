NAME = a.out
SZ = 4
SAN = -fsanitize=leak
FLAG = -Wall -Wextra -Werror -g -D BUFFER_SIZE=$(SZ)
SRC = *.c

.PHONY: all
all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRC)

.PHONY: fclean
fclean:
	rm -rf $(NAME)

.PHONY: re
re: fclean all
