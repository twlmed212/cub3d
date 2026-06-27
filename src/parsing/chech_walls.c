#include "../../includes/cub3d.h"

static void	*check_help(char *str, size_t pos)
{
	if (ft_strlen(str) <= pos || str[pos] == '1' || ft_isspace(str[pos]))
		return (NULL);
	return ((void *)1);
}

static int	check_down(char **map, int j, int i)
{
	int	tmp;
	int	len;

	len = count_element(map);
	tmp = 0;

	while (j + tmp < len)
	{
		if (ft_strlen(map[j + tmp]) > (size_t)i
			&& !ft_isspace(map[j + tmp][i]))
			return (1);

		if (check_help(map[j + tmp], i))
			return (0);

		tmp++;
	}
	return (0);
}
static int	check_up(char **map, int j, int i)
{
	int	tmp;

	tmp = 0;
	while (j - tmp >= 0)
	{
		if (ft_strlen(map[j - tmp]) > (size_t)i
			&& !ft_isspace(map[j - tmp][i]))
			return (1);

		if (check_help(map[j - tmp], i))
			return (0);

		tmp++;
	}
	return (0);
}
void	*ft_space_check(char **map, int j, int *i)
{
	while (map[j][*i] && ft_isspace(map[j][*i]))
	{
		if (!check_up(map, j, *i) || !check_down(map, j, *i)){
			printf("spaces are not surrounded by walls");
			return (NULL);
		}

		(*i)++;
	}
	return ((void *)1);
}
void	*ft_walls(char **map, int row)
{
	int	i;

	i = 0;

	while (map[row][i])
	{
        if (!ft_space_check(map, row, &i))
			return (NULL);
		if (map[row][i] != '1')
		{
			printf("map row : %s\n", map[row]);

			printf("Error\nInvalid wall1111\n");
			return (NULL);
		}
        while (map[row][i] == '1')
			i++;
	}
	return ((void *)1);
}
static void	*ft_side_walls(char **map)
{
    int	j;
    int	i;

    j = 1;
    while (map[j + 1])
    {
        i = 0;
        if (map[i][0] == '\n')
        {
            printf("Error\nInvalid wall2\n");
            return (NULL);
        }
		if (!ft_space_check(map, j, &i))
			return (NULL);
        if (map[j][i] != '1')
        {
            printf("Error\nInvalid wall3\n");
            return (NULL);
        }
        i = ft_strlen(map[j]) - 1;
        while (i >= 0 && ft_isspace(map[j][i]))
            i--;
        if (map[j][i] != '1')
        {
            printf("Error\nInvalid wall4\n");
            return (NULL);
        }
		if (!ft_space_check(map, j, &i))
			return (NULL);
        j++;
    }
    return ((void *)1);
}
void	*check_map_walls(char **map)
{
	if (con_table(map) <= 2){
		printf("Error\nMap must have at least 3 rows\n");
		return (NULL);
	}
	if (!ft_walls(map, 0))
		return (NULL);
	if (!ft_walls(map, con_table(map) - 1))
		return (NULL);
	if (!ft_side_walls(map))
		return (NULL);
	return ((void *)1);
}