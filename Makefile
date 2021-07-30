NAME = libftprintf.a
SOURCES = $(filter-out main.c, $(wildcard *.c))
OBJECTS = $(SOURCES:.c=.o)
LIBFT_NAME = libft.a
LIBFT_PATH = libft/
LIBFT_OBJECTS = $(LIBFT_PATH)*.o

all: $(NAME)

$(NAME): $(OBJECTS) libftmake
	ar rc $(NAME) $(OBJECTS) $(LIBFT_OBJECTS)

bonus: $(NAME)

libftmake:
	make -C $(LIBFT_PATH)

%.o: %.c
	gcc -c -Wall -Wextra -Werror $?

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re
