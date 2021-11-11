#include "../../includes/so_long.h"

int	ft_red_cross(void)
{
	ft_quit("0123", "Error :\nred cross clicked");
	return (0);
}

int print_quit(char *str, char *free, int ord, int abs)
{
	size_t index;
	size_t j;

	index = 0;
	if(str)
		printf("%s\n", str);
	while (index < x()->map->height)
	{
		j = 0;
		printf("line --> %-5zu : \"", index);
		while (x()->map->map[index][j])
		{
			if (ord == index && abs == j || ord == index && abs == -1)
				printf("\033[0;31m%c\033[0m", x()->map->map[index][j]);
			else
				printf("\033[0;32m%c\033[0m", x()->map->map[index][j]);
			j++;
		}
		printf("\"\n");
		index++;
	}
	ft_quit(free, NULL);
	return (0);
}

int	ft_quit(char *str, char *text)
{
	static void (*f[4])() = {free_map, close_window, free_ennemies, free_struct};
	char	c;

	if (text)
		printf("%s\n", text);
	while(*str)
	{
		c = *str;
		if(c >= '0' && c <= '3')
			(f[c - 48])();
		str++;
	}
	// while(1);
	exit(0);
	return (0);
}