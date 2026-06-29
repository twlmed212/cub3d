#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_mac/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define WIN_WIDTH  1280
# define WIN_HEIGHT 720

/* key codes  */
# define KEY_W      119
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100
# define KEY_LEFT   65361
# define KEY_RIGHT  65363
# define KEY_ESC    65307

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_p
{
	int	x;
	int	y;
}	t_p;

typedef struct s_cub
{
	int		fd;
	char	**elem;
	t_p		player;
	char	**map;
	void	*mlx;
	void	*win;
	t_img	img;
}	t_cub;

// parsing
void 	check_ext(char *str, char *ext);
t_cub	*ft_check(char **av);
char	*get_next_line(int fd, int *flag);
void	*ft_get_elements(t_cub *cub);
int		ft_isspace(int c);
int		ft_strcmp(const char *s1, const char *s2);
void	*get_map(t_cub *cub);
int		ft_check_content(char *line);
void	*ft_check_map(t_cub *game, char **table);
void	*ft_find_data(int fd, int *flag);
void	*ft_space_check(char **table, int j, int *i);
size_t	con_table(char **elem);
size_t	count_element(char **str);
void	*ft_map_elements(t_cub *game, char **map);
void	flood_fill(t_cub *game);
void	*ft_walls(char **table, int row);
void	*check_map_walls(char **table);
void	remove_newline(char *str);
void	ft_free_tab(char **tab);

// engine rendring
void	init_engine(t_cub *game);
void	my_pixel_put(t_img *img, int x, int y, int color);
int		render_frame(void *param);
int		key_press(int keycode, void *param);
int		close_window(void *param);

#endif
