#include "../../includes/cub3d.h"

char	**str_dup(char **table)
{
	char	**dest_table;
	int		i;

	dest_table = malloc(sizeof(char *) * (con_table(table) + 1));
	if (!dest_table)
		return (NULL);
	i = 0;
	while (table[i])
	{
		dest_table[i] = ft_strdup(table[i]);
		if (!dest_table[i])
			return (NULL);
		i++;
	}
	dest_table[i] = NULL;
	return (dest_table);
}

static void	ft_flood(char **table, int y, int x)
{
	if (table[y][x] == '1' || table[y][x] == 'F')
		return ;
	table[y][x] = 'F';
	ft_flood(table, y, x + 1);
	ft_flood(table, y, x - 1);
	ft_flood(table, y + 1, x);
	ft_flood(table, y - 1, x);
}

static void	*ft_check_flood(char **table)
{
	int	i;
	int	j;

	i = 0;
	while (table[i])
	{
		j = 0;
		while (table[i][j])
		{
			if (table[i][j] != 'F' && table[i][j] != '1'
				&& !ft_isspace(table[i][j]))
				return (NULL);
			j++;
		}
		i++;
	}
	return ((void *)1);
}

void	ft_free_tab(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	flood_fill(t_cub *game)
{
	char	**cpy_map;

	cpy_map = str_dup(game->map);
	if (!cpy_map){
		printf("Malloc faild");
        exit(1);
    }
	ft_flood(cpy_map, game->player.y, game->player.x);
	if (!ft_check_flood(cpy_map))
	{
		printf("free spaces 0 and player arnt connected");
		ft_free_tab(cpy_map);
		exit(1);
	}
	ft_free_tab(cpy_map);
}