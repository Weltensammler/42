SOURCE = solong.c

OBJECTS = $(SOURCE:.c=.o)

FLAGS = -Werror -Wall -Wextra

NAME = libft.a
NAME2 = mlx.a

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME2): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME2)

all: $(NAME)

$(NAME): $(SOURCE)
	gcc $(FLAGS) $(SOURCE)

clean:
	rm -rf $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all