NAME= libft.a
CC= gcc
FLAGS= -Wall -Wextra -Werror
DEPS= libft.h
OBJECTS= ft_memset.o \
	 ft_bzero.o \
	 ft_memcpy.o \
	 ft_memccpy.o \
	 ft_memmove.o \
	 ft_memchr.o \
	 ft_memcmp.o \
	 ft_strlen.o \
	 ft_strlcpy.o \
	 ft_substr.o

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

%.o: %.c $(DEPS)
	$(CC) $(FLAGS) $< -c -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

_test: $(OBJECTS)
	$(CC) $(FLAGS) -fsanitize=address $^ main.c -g -lbsd

test: _test clean
