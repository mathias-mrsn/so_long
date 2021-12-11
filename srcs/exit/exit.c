#include "../../includes/so_long.h"

int	red_cross(t_data *s)
{
	ft_quit("0123", "Error :\nred cross clicked", s);
	return (0);
}

int print_quit(char *str, char *free, int abs, t_data *s)
{
	int index;
	int j;

	index = 0;
	if (str && __strnstr(str, "Error", INT_MAX))
		__putstr(str, 2);
	else if(str)
		printf("%s\n", str);
	while (index < s->map->height)
	{
		j = 0;
		printf("line --> %-5d : \"", index);
		if (abs == index)
			printf("\033[0;31m%s\033[0m", s->map->map[index]);
		else
			printf("\033[0;32m%s\033[0m", s->map->map[index]);
		j++;
		printf("\"\n");
		index++;
	}
	ft_quit(free, NULL, s);
	return (0);
}

