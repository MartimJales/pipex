CC=cc

CFLAGS = -c -Wall -Wextra -Werror

NAME = pipex

OBJS=$(patsubst %.c,%.o,$(wildcard *.c))

LIBDIR=./libft

LIBS=./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C libft --silent
	@$(CC) $(OBJS) $(LIBS) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) $< -o $@

clean:
	@${MAKE} clean -C libft --silent
	@rm -rf $(OBJS)

fclean: clean
		@${MAKE} fclean -C libft --silent
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

