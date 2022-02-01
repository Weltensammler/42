SOURCE = backup.c check_map.c

OBJECTS = $(SOURCE:.c=.o)

FLAGS = -Werror -Wall -Wextra

NAME = so_long

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx/minilibx_macos -c $< -o $@

$(NAME): $(OBJ)
	make bonus -C ./libft
	make -C ./get_next_line
	$(CC) $(SOURCE) ./libft/libft.a ./get_next_line/get_next_line.a ./mlx/libmlx.a -L /usr/X11/lib -lX11 -lXext -o $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ)  -L /usr/X11/lib -lX11 -lXext -o $(NAME)

# $(NAME): $(SOURCE)
# 	gcc $(FLAGS) $(SOURCE)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all