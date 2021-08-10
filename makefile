SOURCE = ft_atoi.c / ft_bezro.c / ft_isalnum.c / ft_isalpha.c 

OBJECTS = $(SOURCE:.c=.o)

INCLUDE = ./

FLAGS = -Werror -Wall - Wextra

NAME = libft.a

all: $(NAME)

$(NAME): $(SOURCE)
	gcc $(FLAGS) -I$(INCLUDE) -c $(SOURCE)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean: