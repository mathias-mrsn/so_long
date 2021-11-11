#include "../../includes/so_long.h"

void ft_is_done(void)
{
	if (x()->map->pv < 1)
		ft_quit("0123", "Error :\nYou died");
	if (x()->map->map[x()->map->player_x][x()->map->player_y] == 'E' && x()->map->collec == 0)
		ft_quit("0123", "Error :\nCongrats");
}

void ft_collectible(void)
{
	if (x()->map->map[x()->map->player_x][x()->map->player_y] == 'C')
	{
		x()->map->collec--;
		x()->map->map[x()->map->player_x][x()->map->player_y] = '0';
	}
}