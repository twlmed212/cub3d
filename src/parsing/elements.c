#include "../../includes/cub3d.h"

int	ft_check_content(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	*ft_find_data(int fd,int *flag)
{
	char	*str;
	while (1)
	{
		str = get_next_line(fd,flag);
		if (!str && *flag == 1)
			break; 
		remove_newline(str);
		if (!str)
			return (NULL);/// if file is empty
		if (!ft_check_content(str) && *str != '\n')
			break ;
		free(str);
	}
	return (str);
}

size_t	count_element(char **str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	***sort_elements(char ***elements)
{
	int		i;
	char	**str;

	if (!elements)
		return (NULL);
	i = -1;
	while (elements[++i])
	{
		if (elements[i + 1] && ft_strcmp(elements[i][0], elements[i + 1][0]) < 0)
		{
			str = elements[i + 1];
			elements[i + 1] = elements[i];
			elements[i] = str;
			i = -1;
		}
	}
	return (elements);
}
char ***split_elements(char **cub_elem)
{

	char	***elements;
	int		i;

	if (!cub_elem)
		return (NULL);
	elements = malloc(sizeof(char **) * (count_element(cub_elem) + 1));
	if (!elements)
		return (NULL);
	i = 0;
	while (cub_elem[i])
	{
		elements[i] = ft_split(cub_elem[i], ' ');
		if (!elements[i])
		{
			printf("Error\nFailed to split element line\n");
			exit(1);
		}
		i++;
	}
	elements[i] = NULL;
	return (sort_elements(elements));
	
}
static int	check_xpm(char *file)
{
	int	len;

	if (!file)
		return (0);
	len = ft_strlen(file);
	if (len < 4)
		return (0);
	if (ft_strncmp(file + len - 4, ".xpm", 4) != 0)
		return (0);
	return (1);
}
void clean_path(char *str)
{
    int i = ft_strlen(str) - 1;

    while (i >= 0 && (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'))
        str[i--] = '\0';
}
void	check_texture(char **element, char *id)
{
	int	fd;

	if (!element || !element[0] || !element[1])
	{
		printf("Error\nMissing texture path for %s\n", id);
		exit(1);
	}
	clean_path(element[1]);
	/* check identifier */
	if (ft_strcmp(element[0], id) != 0)
	{
		printf("Error\nInvalid texture identifier\n");
		exit(1);
	}

	/* too many arguments */
	if (element[2])
	{
		printf("Error\nToo many arguments for %s\n", id);
		exit(1);
	}

	/* check extension */
	if (!check_xpm(element[1]))
	{
		printf("Error\nTexture must be .xpm : %s\n", element[1]);
		exit(1);
	}

	/* check file exists */
	fd = open(element[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCannot open texture file: %s\n", element[1]);
		exit(1);
	}
	close(fd);
}
static int	ft_isdigit_str(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}


static void	check_rgb_values(char **rgb)
{
	int	i;
	int	n;

	i = 0;
	while (rgb[i])
	{
		if (!ft_isdigit_str(rgb[i]))
		{
			printf("Error\nRGB must contain only numbers\n");
			exit(1);
		}

		n = ft_atoi(rgb[i]);

		if (n < 0 || n > 255)
		{
			printf("Error\nRGB value must be between 0 and 255\n");
			exit(1);
		}
		i++;
	}

	if (i != 3)
	{
		printf("Error\nRGB must contain exactly 3 values\n");
		exit(1);
	}
}

static int	some_checks(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == ','))
			return (0);
		if (str[i] == ',')
			count++;
		if (count > 3)
			return (0);
		i++;
	}
	return (1);
}
void	check_color(char **element, char *id)
{
	char	**rgb;

	if (!element || !element[0] || !element[1])
	{
		printf("Error\nMissing color value for %s\n", id);
		exit(1);
	}

	/* check identifier */
	if (ft_strcmp(element[0], id) != 0)
	{
		printf("Error\nInvalid color identifier\n");
		exit(1);
	}

	/* too many arguments */
	if (element[2])
	{
		printf("Error\nToo many arguments for %s\n", id);
		exit(1);
	}
	clean_path(element[1]);

	if (!some_checks(element[1]))
	{
		printf("Error\nInvalid color format for %s\n", id);
		exit(1);
	}
	/* split rgb */
	rgb = ft_split(element[1], ',');

	if (!rgb)
	{
		printf("Error\nMalloc failed\n");
		exit(1);
	}
	if (count_element(rgb)!=3)
	{
		printf("Error\nRGB must contain exactly 3 values\n");
		exit(1);
	}
	check_rgb_values(rgb);

	ft_free_tab(rgb);
}

void	check_elements(char ***elements){
	int i;

	i = 0;
	while (elements[i])
	{
		if (ft_strncmp(elements[i][0], "NO", 2) == 0)
			check_texture(elements[i], "NO");
		else if (ft_strncmp(elements[i][0], "SO", 2) == 0)
			check_texture(elements[i], "SO");
		else if (ft_strncmp(elements[i][0], "WE", 2) == 0)
			check_texture(elements[i], "WE");
		else if (ft_strncmp(elements[i][0], "EA", 2) == 0)
			check_texture(elements[i], "EA");
		else if (ft_strncmp(elements[i][0], "F", 1) == 0)
			check_color(elements[i], "F");
		else if (ft_strncmp(elements[i][0], "C", 1) == 0)
			check_color(elements[i], "C");
		else
		{
			printf("Error\nInvalid element identifier or wrong extension: %s\n", elements[i][0]);
			exit(1);
		}
		i++;
	}

}
void	*ft_get_elements(t_cub *cub)
{
	int		i;
	char	*line;
	char	***elements;
	int flag = 0;

	cub->elem = malloc(sizeof(char *) * 7);
	if (!(cub->elem))
		return (NULL);
	i = 0;
	while (i < 6)
	{
		line = ft_find_data(cub->fd,&flag);
		if (!line && flag == 1){
			printf("map not found\n");
            exit(1);
        }
		if (!line){
			printf("Malloc failed\n");
            exit(1);
        }
		cub->elem[i++] = line;
		cub->elem[i] = NULL;
	}
	elements = split_elements(cub->elem);
	check_elements(elements);
	return (cub);
}
