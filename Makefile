NAME = cub3D

SRC = cub3d.c \
	  parse_files/ft_check.c \
	  parse_files/check_args.c \
	  parse_files/get_map.c \
	  get_next_line/get_next_line.c \
	  parse_files/elements.c \
	  parse_files/map_elements.c\
	  parse_files/ft_food_fill.c\
	  parse_files/chech_walls.c \
	  parse_files/check_map.c\
	  utils/utilic.c \

	  
 
LIBFT = ./libft/libft.a
INCLUDE = -L ./libft -lft -I ./libft

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft  # Fixed indentation

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean  # Fixed indentation

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean  # Fixed indentation

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
