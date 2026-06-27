#include "../../includes/cub3d.h"

static int	ft_is_map_char(char c)
{
	if (c == '1' || c == '0')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	return (0);
}

static int	ft_set_player(t_cub *game, int y, int x, char c)
{
	(void)c;
	if (game->player.x != 0 || game->player.y != 0)
		return (1);

	game->player.y = y;
	game->player.x = x;

	return (0);
}
static void	*ft_parse_elem(t_cub *game, char **map, int y, int *x)
{
	char	c;
	int		type;

	c = map[y][*x];
	type = ft_is_map_char(c);

	if (!type && !ft_isspace(c))
    {
        		printf("Invalid map element");
                exit(1);
    }
	if (ft_isspace(c))
		return ((void *)1);
	if (type == 2)
	{
		if (ft_set_player(game, y, *x, c)){
			printf("More than one player");
            exit(1);
        }
	}

	(*x)++;

	return ((void *)1);
}

void	*ft_map_elements(t_cub *game, char **map)
{
	int	y;
	int	x;

	y = 1;
	while (map[y + 1])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_space_check(map, y, &x))
				return (NULL);

			if (!ft_parse_elem(game, map, y, &x))
				return (NULL);
		}
		y++;
	}

	if (game->player.x == 0 && game->player.y == 0){
		printf("No player found");
		return (NULL);
	}
	return ((void *)1);
}