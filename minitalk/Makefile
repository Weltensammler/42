NAME_CLIENT = client
NAME_SERVER = server

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFILES_C = client.c
CFILES_S = server.c

OBJ_C := $(CFILES_C:%.c=%.o)
OBJ_S := $(CFILES_S:%.c=%.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(%.o): $(%.c)
	$(CC) $(CFLAGS) -o $@ -c $^

$(NAME_CLIENT): $(OBJ_C)
	$(CC) -o $@ $(OBJ_C)

$(NAME_SERVER): $(OBJ_S)
	$(CC) -o $@ $(OBJ_S)

clean:
	rm -rf $(OBJ_C) $(OBJ_S)

fclean:
	rm -rf $(OBJ_C) $(OBJ_S) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all
