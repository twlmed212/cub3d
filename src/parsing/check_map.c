#include "../../includes/cub3d.h"


static void	conver_spaces(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_isspace(str[i][j]))
				str[i][j] = '1';
			j++;
		}
		i++;
	}
}
void	*ft_check_map(t_cub *game, char **table)
{
	if (!check_map_walls(table))
		return (ft_free_tab(table), NULL);
	if (!ft_map_elements(game, table))
		return (ft_free_tab(table), NULL);
	game->map = table;

	close(game->fd);
	game->fd = -1;
	conver_spaces(game->map);
    flood_fill(game);
return ((void *)1);}