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
	 ft_strlcat.o \
	 ft_strchr.o \
	 ft_strrchr.o \
	 ft_strnstr.o \
	 ft_strncmp.o \
	 ft_atoi.o \
	 ft_is.o \
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

TEST_FLAGS = $(FLAGS) -fsanitize=address -g

ifeq ($(shell uname), Linux)
	TEST_FLAGS := $(TEST_FLAGS) -lbsd
endif

_test: $(OBJECTS)
	$(CC) $(TEST_FLAGS) $^ main.c

test: _test clean
