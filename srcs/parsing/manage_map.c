#include "../../includes/so_long.h"

void ft_get_player_position(t_map *map)
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
			if (x()->map->map[i][j] == 'P')
			{
				x()->map->player_x = i;
				x()->map->player_y = j;
				x()->map->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void ft_add_ennemies(t_map *map)
{
	if (x()->map->grass < 5)
		return;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (x()->map->map[i])
	{
		j = 0;
		while (x()->map->map[i][j])
		{
			if (x()->map->map[i][j] == '0' && !(i == x()->map->player_x && j == x()->map->player_y) && ft_rand(15) == 0) //Creer ft_rand
			{
				if (ft_rand(10) % 2)
					ft_create_ennemies(j, i, ENNEMIE_1);
				else
					ft_create_ennemies(j, i, ENNEMIE_2);
			}
			j++;
		}
		i++;
	}
}