#include "includes/cub3d.h"

int	main(int ac, char **av)
{

	if (ac != 2){
         printf("Usage: ./cub3d <map.cub>\n");
         exit(1);
    }
	ft_check(av);
	return (0);
}