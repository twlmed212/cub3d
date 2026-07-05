NAME    = cub3D
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

UNAME = $(shell uname)
ifeq ($(UNAME), Darwin)
    MLX_DIR   = minilibx_mac
    MLX_FLAGS = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
    MLX_DIR   = minilibx
    MLX_FLAGS = -L $(MLX_DIR) -lmlx -lXext -lX11
endif

LIBFT = ./libft/libft.a
LIBS  = -L ./libft -lft $(MLX_FLAGS) -lm
INCS  = -I ./includes -I ./libft -I $(MLX_DIR)

SRC =	src/main.c \
		src/parsing/ft_check.c \
		src/parsing/check_args.c \
		src/parsing/get_map.c \
		src/parsing/elements.c \
		src/parsing/map_elements.c \
		src/parsing/ft_food_fill.c \
		src/parsing/chech_walls.c \
		src/parsing/check_map.c \
		src/utils/utilic.c \
		get_next_line/get_next_line.c \
		src/engine/init.c \
		src/engine/render.c \
		src/engine/hooks.c	\
		src/engine/player.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $@

$(LIBFT):
	$(MAKE) -C libft

all: $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
