
NAME = libft.a

SRC = ft_atoi.c ft_memcmp.c ft_strchr.c ft_strmapi.c ft_toupper.c \
      ft_bzero.c ft_memcpy.c ft_strdup.c ft_strncmp.c \
      ft_calloc.c ft_memmove.c ft_striteri.c ft_strnstr.c \
      ft_isalnum.c ft_memset.c ft_strjoin.c ft_strrchr.c \
      ft_isalpha.c ft_putchar_fd.c ft_strlcat.c ft_strtrim.c \
      ft_isdigit.c ft_putendl_fd.c ft_strlcpy.c ft_substr.c \
      ft_itoa.c ft_putstr_fd.c ft_strlen.c ft_tolower.c ft_putnbr_fd.c \
	  ft_isascii.c ft_isprint.c ft_memchr.c ft_split.c

OBJ = ${SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Rules for compiling object files
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create static library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Clean object files
clean:
	rm -f $(OBJ)

# Clean all generated files
fclean: clean
	rm -f $(NAME)

# Rebuild all
re: fclean all

# Default target
all: $(NAME)

.PHONY : all clean fclean re

