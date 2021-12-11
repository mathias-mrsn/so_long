#include "../../includes/so_long.h"

static void __ennemies_up__(t_data *s, int *i, int *y)
{
	(*y)++;
	if (*y == s->map->player_x && *i == s->map->player_y)
		s->map->pv -= DAMAGE_PER_ENNEMIE;
}

static void __ennemies_down__(t_data *s, int *i, int *y)
{
	(*y)--;
	if (*y == s->map->player_x && *i == s->map->player_y)
		s->map->pv -= DAMAGE_PER_ENNEMIE;
}

static void __ennemies_left__(t_data *s, int *i, int *y)
{
	(*i)--;
	if (*y == s->map->player_x && *i == s->map->player_y)
		s->map->pv -= DAMAGE_PER_ENNEMIE;
}

static void __ennemies_right__(t_data *s, int *i, int *y)
{
	(*i)++;
	if (*y == s->map->player_x && *i == s->map->player_y)
		s->map->pv -= DAMAGE_PER_ENNEMIE;
}

void ft_move_ennemies(t_data *s)
{
	t_ennemies *tmp;
	int rand;

	tmp = s->ennemies;
	while (tmp)
	{
		rand = __random(4);
		if (__random(20) == 0)
		{
			if (rand == 0 && s->map->map[tmp->y - 1][tmp->x] != '1' && !__is_ennemie__(s, tmp->x, tmp->y - 1))
				__ennemies_down__(s, &tmp->x, &tmp->y);
			else if (rand == 1 && s->map->map[tmp->y + 1][tmp->x] != '1' && !__is_ennemie__(s, tmp->x, tmp->y + 1))
				__ennemies_up__(s, &tmp->x, &tmp->y);
			else if (rand == 2 && s->map->map[tmp->y][tmp->x - 1] != '1' && !__is_ennemie__(s, tmp->x - 1, tmp->y))
				__ennemies_left__(s, &tmp->x, &tmp->y);
			else if (rand == 3 && s->map->map[tmp->y][tmp->x + 1] != '1' && !__is_ennemie__(s, tmp->x + 1, tmp->y))
				__ennemies_right__(s, &tmp->x, &tmp->y);
		}
		tmp = tmp->next;
	}
}