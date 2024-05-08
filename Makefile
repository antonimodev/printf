NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_aux_pf.c ft_putchar_pf.c \
	ft_putnbr_pf.c ft_putstr_pf.c ft_putmayushex_pf.c\
	ft_putminushex_pf.c ft_putunsnbr_pf.c \
	ft_putptr_pf.c

OBJ = $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all clean fclean re