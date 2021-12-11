#include "../../includes/so_long.h"

void ft_get_player_position(t_map *map)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->player_x = i;
				map->player_y = j;
				map->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void ft_add_ennemies(t_data *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s->map->grass < 5 || !BONUS)
		return;
	while (s->map->map[i])
	{
		j = 0;
		while (s->map->map[i][j])
		{
			if (s->map->map[i][j] == '0' && !(i == s->map->player_x && j == s->map->player_y) && __random(15) == 0)
			{
				if (__random(10) % 2)
					ft_create_ennemies(s, j, i, ENNEMIE_1);
				else
					ft_create_ennemies(s, j, i, ENNEMIE_2);
			}
			j++;
		}
		i++;
	}
}