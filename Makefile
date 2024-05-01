NAME = libftprintf.a

SRC = ft_printf.c 

all: $(NAME)

clean:
	rm -rf

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY