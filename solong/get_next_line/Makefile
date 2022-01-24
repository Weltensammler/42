SOURCE = get_next_line.c get_next_line_utils.c

OBJECTS = $(SOURCE:.c=.o)

FLAGS = -Werror -Wall -Wextra

NAME = get_next_line.a

INCLUDE = ./

all: $(NAME)

$(NAME): $(SOURCE)
	gcc $(FLAGS) -I$(INCLUDE) -c $(SOURCE)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all