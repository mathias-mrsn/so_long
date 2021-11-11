#include "../../includes/so_long.h"

int ft_is_rectangle(t_map *map)
{
	size_t len;
	size_t i;

	len = ft_strlen(map->map[0]);
	i = 1;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != len)
		{
			if (i == 1 && map->map[2] && len != ft_strlen(map->map[2]))
				print_quit("Error :\nthe map isn't a rectangle", "03", i - 1, -1);
			else
				print_quit("Error :\nthe map isn't a rectangle", "03", i, -1);
		}
		i++;
	}
	map->width = len;
	if (x()->map->width < 3 || x()->map->height < 3)
		ft_quit("14", "Error :\nmap is too small");
	return (0);
}

int ft_check_exit(t_map *map)
{
	if (x()->map->exit < 1)
		ft_quit("03", "Error :\nNo exit on the map");
	if (x()->map->player < 1)
		ft_quit("03", "Error :\nNo player on the map");
	if (x()->map->player > 1)
		ft_quit("03", "Error :\nto many players on the map");
	if (x()->map->collec < 1)
		ft_quit("03", "Error :\nNo collectible on the map");
	return (0);
}

int ft_is_correct_map(t_map *map)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (x()->map->map[i])
	{
		j = 0;
		while (x()->map->map[i][j])
		{
			if (x()->map->map[i][j] == 'C')
				map->collec++;
			if (x()->map->map[i][j] == 'P')
				map->player++;
			if (x()->map->map[i][j] == 'E')
				map->exit++;
			if (x()->map->map[i][j] == '0')
				map->grass++;
			if (!ft_is_charset(x()->map->map[i][j], ELEM_MAP))
				print_quit("Error :\ninvalid element ont the map", "03", i, j);
			j++;
		}
		i++;
	}
	ft_check_exit(map);
	return (0);
}

int ft_is_surrended_by_walls(t_map *map)
{
	size_t i;
	size_t j;

	i = -1;
	j = -1;
	while (++i < map->height)
		if (map->map[i][0] != '1')
			print_quit("Error :\nisn't surrended by walls", "03", i, 0);
	while (++j < map->width)
		if (map->map[0][j] != '1')
			print_quit("Error :\nisn't surrended by walls", "03", 0, j);
	while (--i > -1)
		if (map->map[i][j - 1] != '1')
			print_quit("Error :\nisn't surrended by walls", "03", i, j - 1);
	while (--i > -1)
		if (map->map[map->height - 1][j] != '1')
			print_quit("Error :\nisn't surrended by walls", "03", map->height - 1, j);
	return (0);
}

int ft_map_check(t_map *map, int argc, char **argv)
{
	size_t file_name_len;
	int	fd;

	if (argc < 2)
		ft_quit("3", "Error :\nno argument");
	if (argc > 2)
		ft_quit("3", "Error :\ntoo many arguments");

	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		ft_quit("3", "Error :\nno such file or directory");
	close(fd);

	file_name_len = strlen(argv[1]);
	if (ft_strncmp(&argv[1][file_name_len - 4], ".ber", 4))
		ft_quit("3", "bad file extension");
	ft_get_map(map, argc, argv);
	ft_is_correct_map(map);
	ft_is_rectangle(map);
	ft_is_surrended_by_walls(map);
	ft_get_player_position(map);
	ft_add_ennemies(map);
	return (0);
}