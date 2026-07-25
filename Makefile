NAME    = cub3D
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

MLX_DIR = minilibx
MLX     = $(MLX_DIR)/libmlx.a
LIBFT   = ./libft/libft.a
LIBS    = -L ./libft -lft -L $(MLX_DIR) -lmlx -lXext -lX11 -lm
INCS    = -I ./includes -I ./libft -I $(MLX_DIR)

SRC =	src/main.c \
		src/cleaner/cleanup.c \
		src/parsing/ft_check.c \
		src/parsing/get_map.c \
		src/parsing/elements.c \
		src/parsing/elements2.c \
		src/parsing/map_elements.c \
		src/parsing/check_walls.c \
		src/parsing/check_map.c \
		src/parsing/error.c \
		src/utils/utils.c \
		src/utils/utils_elements.c \
		src/utils/utils_elements1.c \
		src/utils/utils_check_walls.c \
		get_next_line/get_next_line.c \
		src/engine/init.c \
		src/engine/render.c \
		src/engine/hooks.c	\
		src/engine/dda.c	\
		src/engine/move.c	\
		src/engine/draw.c	\
		src/engine/textures.c	\
		src/engine/player.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $@

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C $(MLX_DIR)

all: $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re norm leak testbad
