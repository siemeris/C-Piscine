NAME = bsq

MY_SOURCES = main.c \
			 check_matrix.c \
			 check_inputs.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

.PHONY: fclean all clean

all: $(NAME)

CFLAGS += -Wall -Wextra -Werror

$(NAME): $(MY_OBJECTS)
	cc $(CFLAGS) -o $(NAME) $(MY_OBJECTS)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
