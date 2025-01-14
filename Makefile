NAME = fractol
SRC = srcs/main.c
OBJ = $(SRC:.c=.o)
MLX = minilibx-linux
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux
LFLAGS = -L$(MLX) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(MLX) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
