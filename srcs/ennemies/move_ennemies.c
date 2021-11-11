#include "../../includes/so_long.h"

void ft_ennemies_up(int *i, int *y)
{
	(*y)++;
	if (*y == x()->map->player_x && *i == x()->map->player_y)
		x()->map->pv -= DAMAGE_PER_ENNEMIE;
}

void ft_ennemies_down(int *i, int *y)
{
	(*y)--;
	if (*y == x()->map->player_x && *i == x()->map->player_y)
		x()->map->pv -= DAMAGE_PER_ENNEMIE;
}

void ft_ennemies_left(int *i, int *y)
{
	(*i)--;
	if (*y == x()->map->player_x && *i == x()->map->player_y)
		x()->map->pv -= DAMAGE_PER_ENNEMIE;
}

void ft_ennemies_right(int *i, int *y)
{
	(*i)++;
	if (*y == x()->map->player_x && *i == x()->map->player_y)
		x()->map->pv -= DAMAGE_PER_ENNEMIE;
}

void ft_move_ennemies()
{
	t_ennemies *tmp;
	int rand;

	tmp = x()->ennemies;
	while (tmp)
	{
		rand = ft_rand(4);
		if (ft_rand(20) == 0)
		{
			if (rand == 0 && x()->map->map[tmp->y - 1][tmp->x] != '1' && !ft_is_ennemies(tmp->x, tmp->y - 1))
				ft_ennemies_down(&tmp->x, &tmp->y);
			else if (rand == 1 && x()->map->map[tmp->y + 1][tmp->x] != '1' && !ft_is_ennemies(tmp->x, tmp->y + 1))
				ft_ennemies_up(&tmp->x, &tmp->y);
			else if (rand == 2 && x()->map->map[tmp->y][tmp->x - 1] != '1' && !ft_is_ennemies(tmp->x - 1, tmp->y))
				ft_ennemies_left(&tmp->x, &tmp->y);
			else if (rand == 3 && x()->map->map[tmp->y][tmp->x + 1] != '1' && !ft_is_ennemies(tmp->x + 1, tmp->y))
				ft_ennemies_right(&tmp->x, &tmp->y);
		}
		tmp = tmp->next;
	}
}