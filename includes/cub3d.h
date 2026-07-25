/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:44:09 by mtawil            #+#    #+#             */
/*   Updated: 2026/07/25 13:29:19 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define WIN_WIDTH  1280
# define WIN_HEIGHT 720

# define KEY_W      119
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100
# define KEY_LEFT   65361
# define KEY_RIGHT  65363
# define KEY_ESC    65307

# define MOVE_SPEED  0.1
# define ROT_SPEED   0.05

# define INF_DIST    1e30

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
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	cam_distance;
	int		line_h;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_p
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_p;

typedef struct s_cub
{
	int				fd;
	char			**elem;
	t_p				player;
	char			**map;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	void			*mlx;
	void			*win;
	t_tex			img;
	t_tex			tex[4];
}	t_cub;

/* parsing */
void			check_ext(char *str, char *ext);
t_cub			*ft_check(char **av);
char			*get_next_line(int fd, int *flag);
void			*ft_get_elements(t_cub *cub);
int				ft_isspace(int c);
int				ft_strcmp(const char *s1, const char *s2);
void			*get_map(t_cub *cub);
int				ft_check_content(char *line);
void			*ft_check_map(t_cub *game, char **table);
void			*ft_find_data(int fd, int *flag);
void			*ft_space_check(char **table, int j, int *i);
size_t			con_table(char **elem);
size_t			count_element(char **str);
void			*ft_map_elements(t_cub *game, char **map);
void			*ft_walls(char **table, int row);
void			*check_map_walls(char **table);
void			remove_newline(char *str);
unsigned char	*check_rgb_values(char **rgb);
void			check_texture(char **element, char *id);
char			***split_elements(char **cub_elem);
void			clean_path(char *str);
int				some_checks(char *str);
int				ft_isdigit_str(char *str);
int				check_xpm(char *file);
void			print_error_rgb(const char *message);
void			print_error_get_elem(char *message);
void			print_error(const char *message, const char *id);
void			error_space(char *message);
void			print_error_map(char *message);
int				valid_ids(char ***e);
int				space_run_ok(char *row, int x);
void			check_elements(t_cub *cub, char ***elements);
void			check_color(char **element, t_cub *cub, char *id);

/* engine */
void			init_engine(t_cub *game);
void			my_pixel_put(t_tex *img, int x, int y, int color);
int				render_frame(void *param);
int				key_press(int keycode, void *param);
int				close_window(void *param);
void			init_player(t_cub *game);
void			cast_ray(t_cub *game, t_ray *ray, int x);
void			walk(t_cub *game, int d);
void			walk_sideways(t_cub *game, int d);
void			rotate(t_cub *game, double a);
void			init_textures(t_cub *game);
void			calc_wall(t_ray *ray);
void			draw_column(t_cub *game, t_ray *ray, int x);
int				is_wall_point(t_cub *game, double x, double y);
int				touch_wall(t_cub *game, double x, double y);

/* garber colletor */
typedef struct s_gc
{
	void		*data;
	struct s_gc	*next;
}	t_gc;

void			*ft_malloc(size_t size);
void			free_grabage(void);

#endif
