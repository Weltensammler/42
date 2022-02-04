SOURCE = so_long.c check_map1.c check_map2.c solong_utils.c\
load_images.c end_game.c player_move.c imagefails.c

OBJECTS = $(SOURCE:.c=.o)

FLAGS = -Werror -Wall -Wextra

NAME = so_long

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -C ./mlx
	make bonus -C ./libft
	make -C ./get_next_line
	$(CC) $(SOURCE) ./libft/libft.a ./get_next_line/get_next_line.a\
	 ./mlx/libmlx.a -L /usr/X11/lib -lX11 -lXext -o $(NAME)

clean:
	make clean -C ./mlx
	make clean -C ./libft
	make clean -C ./get_next_line
	rm -rf $(OBJECTS)

fclean: clean
	make fclean -C ./libft
	make fclean -C ./get_next_line
	rm -rf $(NAME)

re: fclean all