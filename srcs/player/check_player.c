#include "../../includes/so_long.h"

void ft_is_done(t_data *s)
{
	if (s->map->pv < 1)
		ft_quit("0123", "Error :\nYou died", s);
	if (s->map->map[s->map->player_x][s->map->player_y] == 'E' && s->map->collec == 0)
		ft_quit("0123", "Error :\nCongrats", s);
}

void ft_collectible(t_data *s)
{
	if (s->map->map[s->map->player_x][s->map->player_y] == 'C')
	{
		s->map->collec--;
		s->map->map[s->map->player_x][s->map->player_y] = '0';
	}
}