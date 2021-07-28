NAME = libftprintf.a
SOURCES = $(filter-out main.c, $(wildcard *.c))
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	cd libft; make; cp libft.a ../$(NAME); make fclean;
	ar rc $@ $?

%.o: %.c
	gcc -c -Wall -Wextra -Werror $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
