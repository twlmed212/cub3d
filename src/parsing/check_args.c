#include "../../includes/cub3d.h"

void	check_args(char **av,const char *ext)
{
	int	len;

	len = strlen(av[1]);

	if (len < 5 || *(av[1] + len - 5) == '/')
	{
		printf("Error\nInvalid path\n");
		exit(1);
	}

	if (ft_strncmp(av[1] + len - 4, ext, 4) != 0)
	{
		printf("Error\nInvalid map extension\n");
		exit(1);
	}
}


