.PHONY: all clean fclean re bonus

NAME= libft.a
CC= gcc
FLAGS= -Wall -Wextra -Werror
DEPS= libft.h
INCLUDES=./
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
		 ft_isalpha.o \
		 ft_isdigit.o \
		 ft_isalnum.o \
		 ft_isascii.o \
		 ft_isprint.o \
		 ft_toupper.o \
		 ft_tolower.o \
		 ft_calloc.o \
		 ft_strdup.o \
		 ft_substr.o \
		 ft_strjoin.o \
		 ft_strtrim.o \
		 ft_split.o \
		 ft_itoa.o \
		 ft_strmapi.o \
		 ft_putchar_fd.o \
		 ft_putstr_fd.o \
		 ft_putendl_fd.o \
		 ft_putnbr_fd.o
BONUS= ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o \
	   ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -I$(INCLUDES) $< -c -o $@

clean:
	rm -f $(OBJECTS) $(BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS) $(BONUS)
	ar rcs $(NAME) $^
