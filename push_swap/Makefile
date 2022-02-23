SOURCE = push_swap.c push_swap_operations1.c push_swap_utils.c

OBJECTS = $(SOURCE:.c=.o)

FLAGS = -Werror -Wall -Wextra

NAME = push_swap

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make bonus -C ./libft
	make -C ./ft_printf
	$(CC) $(SOURCE) ./libft/libft.a ./ft_printf/ft_printf.a -o $(NAME)

clean:
	make clean -C ./libft
	make clean -C ./ft_printf
	rm -rf $(OBJECTS)

fclean: clean
	make fclean -C ./libft
	make fclean -C ./ft_printf
	rm -rf $(NAME)

re: fclean all