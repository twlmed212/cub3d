#include "../includes/cub3d.h"

int	ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

char	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
void	remove_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
        return;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			return ;
		}
		i++;
	}
}