NAME = fractol
OBJ = $(SRCS:.c=.o)
MLX = minilibx-linux
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX)
LFLAGS = -L$(MLX) -lmlx -lXext -lX11 -lm


SRCS := srcs/main.c srcs/draw_mandel.c srcs/color.c srcs/draw_background.c srcs/julia.c srcs/utils_mouse.c \
	srcs/utils_keys.c


all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(MLX) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(MLX) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

