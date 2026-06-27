#include "../../includes/cub3d.h"

static int	open_file(char *fname)
{
	int	fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0){
		printf("Error\nFailed to open the file\n");
        exit(1);
	}
	return (fd);
}

void    check_ext(char *str, char *ext){

    size_t	len;

	len = ft_strlen(str);
	if (len <= 4 || *(str + len - 5) == '/'){
		printf("filename invalide");
        exit(1);
    }
	if (ft_strcmp(str + len - 4, ext)){
		printf("Wrong extantion name");
        exit(1);
    }
}

t_cub *ft_check(char **av){

        t_cub *cub;   
        check_ext(av[1],".cub");

        cub = malloc(sizeof(t_cub));
        if (!cub){
            printf("Error\nFailed to allocate memory for cub structure\n");
            exit(1);
        }
        cub->fd = open_file(av[1]);
        ft_get_elements(cub);
        get_map(cub);
        return (cub);

}