SOURCE = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memmove.c\
ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
ft_strchr.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
ft_substr.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_strlcat.c ft_strdup.c\
ft_memcpy.c ft_split.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c

OBJECTS = $(SOURCE:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJECTS = $(BONUS:.c=.o)

INCLUDE = ./

FLAGS = -Werror -Wall -Wextra

NAME = libft.a

all: $(NAME)

$(NAME): $(SOURCE)
	gcc $(FLAGS) -I$(INCLUDE) -c $(SOURCE)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	ar rc $(NAME) $(OBJECTS) $(BONUS_OBJECTS)