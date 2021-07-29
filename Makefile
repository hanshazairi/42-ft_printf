NAME = libftprintf.a
SOURCES = $(filter-out main.c, $(wildcard *.c))
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	cd libft; make; cp libft.a ../$(NAME);
	ar rc $@ $?

%.o: %.c
	gcc -c -Wall -Wextra -Werror $?

clean:
	cd libft; make clean;
	rm -f $(OBJECTS)

fclean: clean
	cd libft; make fclean;
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
