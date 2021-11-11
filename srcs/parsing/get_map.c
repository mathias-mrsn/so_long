#include "../../includes/so_long.h"

int ft_file_height(char *str)
{
	int fd;
	char c;
	int len;

	len = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			len++;
	close(fd);
	return (len + 1);
}

int ft_get_map(t_map *map, int argc, char **argv)
{
	char *str;
	size_t i;
	size_t fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_quit("3", "Error :\ncouldn't open file'");
	map->map = malloc(sizeof(char *) * (ft_file_height(argv[1]) + 1));
	if (!map->map)
		ft_quit("03", "Error :\nmemory errors");
	str = get_next_line(fd);
	while (str)
	{
		map->map[i++] = str;
		map->height++;
		str = get_next_line(fd);
	}
	map->map[i] = NULL;
	close(fd);
	return (0);
}