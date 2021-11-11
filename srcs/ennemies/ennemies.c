#include "../../includes/so_long.h"

t_ennemies *ft_create_elem(int a, int b, char *file)
{
	t_ennemies *new;

	new = malloc(sizeof(t_ennemies) * 1);
	if (!new)
		return (NULL);
	new->x = a;
	new->y = b;
	new->next = NULL;
	new->texture = ft_strdup(file);
	return (new);
}

void ft_create_ennemies(int i, int j, char *file)
{
	t_ennemies *new;

	if (!x()->ennemies)
		x()->ennemies = ft_create_elem(i, j, file);
	else
	{
		new = ft_create_elem(i, j, file);
		new->next = x()->ennemies;
		x()->ennemies = new;
	}
}

int ft_is_ennemies(int i, int j)
{
	t_ennemies *tmp;

	tmp = x()->ennemies;
	while (tmp)
	{
		if (tmp->x == i && tmp->y == j)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void ft_ennemies_on_player(void)
{
	if (ft_is_ennemies(x()->map->player_y, x()->map->player_x))
		x()->map->pv -= DAMAGE_PER_ENNEMIE;
	return;
}

char *ft_get_ennemie_text(int i, int j)
{
	t_ennemies *tmp;

	tmp = x()->ennemies;
	while (tmp)
	{
		if (tmp->x == i && tmp->y == j)
			return (tmp->texture);
		tmp = tmp->next;
	}
	return (NULL);
}