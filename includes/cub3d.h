#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define WIN_WIDTH  1280
# define WIN_HEIGHT 720

/* key codes (Linux / X11) */
# define KEY_W      119
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100
# define KEY_LEFT   65361
# define KEY_RIGHT  65363
# define KEY_ESC    65307

# define MOVE_SPEED  0.1
# define ROT_SPEED   0.05


typedef struct s_tex
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_tex;

typedef struct s_ray
{
    double  ray_dir_x;
    double  ray_dir_y;
    int     map_x;
    int     map_y;
    double  delta_dist_x;
    double  delta_dist_y;
    double  side_dist_x;
    double  side_dist_y;
    int     step_x;
    int     step_y;
    int     side;
    double  perp_dist;
    int     line_h;
    int     draw_start;
    int     draw_end;
}   t_ray;
typedef struct s_p
{
	double	x;
	double	y;
	double	dir_y;
	double	dir_x;
	double	plane_x;
	double	plane_y;
}	t_p;

typedef struct s_cub
{
	int		fd;
	char	**elem;
	t_p		player;
	char	**map;
	void	*mlx;
	void	*win;
	t_tex	img;
	t_tex	tex[4];
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
void	my_pixel_put(t_tex *img, int x, int y, int color);
int		render_frame(void *param);
int		key_press(int keycode, void *param);
int		close_window(void *param);
void	init_player(t_cub *game);
void	cast_ray(t_cub *game, t_ray *ray, int x);
void	walk(t_cub *game, int d);
void	walk_sideways(t_cub *game, int d);
void	rotate(t_cub *game, double a);
void	init_textures(t_cub *game);
void	calc_wall(t_ray *ray);
void	draw_column(t_cub *game, t_ray *ray, int x);

#endif
