#include "../../includes/cub3d.h"

static void *check_line(int fd)
{
    char    *line;
    int     flag = 0;
    
    while (1)
    {
        line = get_next_line(fd, &flag);
        if (!line)
        {
            if (flag == 1)
                break; // الخروج هنا آمن لأن line هو NULL بالفعل
            return (NULL);
        }
        
        remove_newline(line);
        // تأكد أن remove_newline لا تغير قيمة المؤشر line بل تغير المحتوى فقط
        
        if (!*line)
        {
            free(line); // يجب تنظيف السطر الفارغ قبل عمل break!
            line = NULL;
            break ;
        }
        
if (*line != '\n' && !ft_check_content(line))
{
    printf("The map is sperited\n");
    // free(line); <-- قمنا بحذف هذا السطر لأنه تم تفريغه داخل ft_check_content
    line = NULL; 
    return (NULL);
}
        
        // إذا مر السطر بسلام، نقوم بتفريغه وتصفيره للاستعداد للسطر القادم
        free(line);
        line = NULL; 
    }
    return ((void *)1);
}
size_t	con_table(char **elem)
{
	size_t	i;

	if (!elem)
		return (0);
	i = 0;
	while (elem[i])
		i++;
	return (i);
}
void	*add_map(char **line, char *str)
{
	char	**lines;
	int		i;

	lines = malloc((con_table(line) + 2) * sizeof(char *));
	if (!lines)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		lines[i] = line[i];
		i++;
	}
	lines[i++] = str;
	lines[i] = NULL;
	free(line);
	return (lines);
}
 
void *get_map(t_cub *cub){

    char	*line;
	char	**lines;
	int 	flag = 0;
	lines = NULL;
	line = ft_find_data(cub->fd,&flag); // Get the first line of the map, skipping empty lines and lines with only spaces //هاد function كتقلب على أول line فيها content.
	if (!line && flag == 1)
	{
		printf("map not found\n");
		exit(1);
	}
	while (1)
	{
		if (!line)
			return (NULL);
		if (!*line || ft_check_content(line) || *line == '\n') // If the line is empty, contains only spaces, or is a newline, it indicates the end of the map.
			break ;
		lines = add_map(lines, line); // Add the line to the table. This function reallocates the table to accommodate the new line and adds it to the end of the table.
		if (!lines)
			return (NULL);
		line = get_next_line(cub->fd,&flag);// Get the next line of the map.
		if (!line)
		{
    	if (flag == 1)
        	break;
    	return NULL;
		}
		remove_newline(line);
	}

	if (!check_line(cub->fd))
		return (free(line),NULL);
	return (free(line), ft_check_map(cub, lines));
}

