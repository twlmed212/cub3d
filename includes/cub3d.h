#ifndef CUB3D_H
# define CUB3D_H

#include "stdio.h"
#include <stdlib.h>
#include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"

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
    int             fd;
    char			**elem;
	t_p		        player;
    char			**map;

            
} t_cub;

void    check_ext(char *str, char *ext);
t_cub	*ft_check(char **av);
char	*get_next_line(int fd,int *flag);

void	*ft_get_elements(t_cub *cub);
int	ft_isspace(int c);
char	ft_strcmp(const char *s1, const char *s2);

void *get_map(t_cub *cub);
int	ft_check_content(char *line);
void	*ft_check_map(t_cub *game, char **table);
void	*ft_find_data(int fd,int *flag);

void	*ft_space_check(char **table, int j, int *i);
size_t	con_table(char **elem);
size_t	count_element(char **str);
void	*ft_map_elements(t_cub *game, char **map);
void	flood_fill(t_cub *game);
void	*ft_walls(char **table, int row);
void	*check_map_walls(char **table);
void	remove_newline(char *str);

void	ft_free_tab(char **tab);


#endif
