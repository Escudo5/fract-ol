NAME = fractol
OBJ = $(SRCS:.c=.o)
MLX = minilibx-linux
LIBFT_DIR = ./custom-libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror  -fPIC -Iincludes -I$(MLX) -I$(LIBFT_DIR)
LFLAGS = -L$(MLX) -lmlx -lXext -lX11 -lm $(LIBFT) -no-pie


SRCS := srcs/main2.c srcs/draw_mandel.c srcs/color.c srcs/draw_background.c srcs/julia.c srcs/utils_mouse.c \
	srcs/utils_keys.c srcs/var_utils.c srcs/window_control.c srcs/burning.c

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(MLX) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(MLX) clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

