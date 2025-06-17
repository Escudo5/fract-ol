NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

CFILES = ft_hexadec.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbru.c ft_putptr.c ft_putstr.c 

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	cc $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
