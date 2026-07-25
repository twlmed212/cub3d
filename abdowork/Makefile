NAME = cub3D

SRC = cub3d.c \
	  parse_files/ft_check.c \
	  parse_files/check_args.c \
	  parse_files/get_map.c \
	  get_next_line/get_next_line.c \
	  parse_files/elements.c \
	  parse_files/map_elements.c\
	  parse_files/check_walls.c \
	  parse_files/check_map.c\
	  parse_files/error.c\
	  utils/utils_elements.c\
	  utils/utils_elements1.c\
	  utils/utils.c \


	  
 
LIBFT = ./libft/libft.a
INCLUDE = -L ./libft -lft -I ./libft

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Rules for compiling object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create executable
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

# Ensure libft is compiled
$(LIBFT):
	$(MAKE) -C libft  # Fixed indentation

# Clean object files
clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean  # Fixed indentation

# Clean all generated files
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean  # Fixed indentation

# Rebuild all
re: fclean all

# Default target
all: $(NAME)

.PHONY: all clean fclean re
