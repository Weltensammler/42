SOURCE = philosophers.c philosophers_utils.c eating.c cycle.c

OBJECTS = $(SOURCE:.c=.o)

FLAGS = -Werror -Wall -Wextra -pthread

NAME = philosophers

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -pthread -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(SOURCE) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all