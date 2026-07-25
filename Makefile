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

# run every invalid map under valgrind; must be 0 leaks / 0 crashes / 0 accepted
testbad: all
	@xvfb-run -a bash -c 'l=0; c=0; a=0; \
		for f in maps/bad/*.cub; do \
			o=$$(timeout 6 valgrind --leak-check=full --suppressions=mlx.supp ./cub3D $$f 2>&1); s=$$?; \
			st=ok; echo "$$o" | grep -q "no leaks are possible" || { st=LEAK; l=$$((l+1)); }; \
			[ $$s -eq 139 ] && { st=SEGV; c=$$((c+1)); }; \
			[ $$s -eq 124 ] && { st=ACCEPTED; a=$$((a+1)); }; \
			printf "%-24s %s\n" "$$(basename $$f .cub)" "$$st"; \
		done; echo "--- LEAKS=$$l CRASHES=$$c ACCEPTED=$$a ---"'

# check the norm on our own code only (skip libft / minilibx / gnl)
norm:
	norminette includes/ src/

# run under a virtual display + valgrind, auto-close via ESC so it exits clean
leak: all
	xvfb-run -a --server-args="-screen 0 1280x720x24" bash -c '\
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
			--suppressions=mlx.supp ./cub3D maps/a3.cub & \
		VP=$$!; sleep 5; \
		WID=$$(xdotool search --name Mok3ab3D | head -1); \
		xdotool key --window $$WID Escape; \
		wait $$VP'

.PHONY: all clean fclean re norm leak testbad
