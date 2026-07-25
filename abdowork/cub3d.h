/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 06:44:14 by abmoudni          #+#    #+#             */
/*   Updated: 2026/07/23 07:05:51 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "stdio.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_p
{
	int				x;
	int				y;

}					t_p;

typedef struct s_cub
{
	int				fd;
	char			**elem;
	t_p				player;
	char			**map;
	unsigned int	floor_color;
	unsigned int	ceiling_color;

}					t_cub;

void				check_ext(char *str, char *ext);
t_cub				*ft_check(char **av);
char				*get_next_line(int fd, int *flag);

void				*ft_get_elements(t_cub *cub);
int					ft_isspace(int c);
char				ft_strcmp(const char *s1, const char *s2);

void				*get_map(t_cub *cub);
int					ft_check_content(char *line);
void				*ft_check_map(t_cub *game, char **table);
void				*ft_find_data(int fd, int *flag);

void				*ft_space_check(char **table, int j, int *i);
size_t				con_table(char **elem);
size_t				count_element(char **str);
void				*ft_map_elements(t_cub *game, char **map);
void				*ft_walls(char **table, int row);
void				*check_map_walls(char **table);
void				remove_newline(char *str);

unsigned char		*check_rgb_values(char **rgb);
void				check_texture(char **element, char *id);
char				***split_elements(char **cub_elem);
void				clean_path(char *str);
int					some_checks(char *str);
int					ft_isdigit_str(char *str);
int					check_xpm(char *file);

void print_error_rgb(const char *message);
void	print_error_get_elem(char *message);
void	print_error(const char *message, const char *id);
void	error_space(char *message);

void				ft_free_tab(char **tab);

#endif
