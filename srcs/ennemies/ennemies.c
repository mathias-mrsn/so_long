/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:56:44 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/11 18:56:56 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_ennemies	*__create_elem__(int a, int b, char *file)
{
	t_ennemies	*new;

	new = malloc(sizeof(t_ennemies) * 1);
	if (!new)
		return (NULL);
	new->x = a;
	new->y = b;
	new->next = NULL;
	new->texture = ft_strdup(file);
	return (new);
}

void	ft_create_ennemies(t_data *s, int i, int j, char *file)
{
	t_ennemies	*new;

	if (!s->ennemies)
		s->ennemies = __create_elem__(i, j, file);
	else
	{
		new = __create_elem__(i, j, file);
		new->next = s->ennemies;
		s->ennemies = new;
	}
}

int	__is_ennemie__(t_data *s, int i, int j)
{
	t_ennemies	*tmp;

	tmp = s->ennemies;
	while (tmp)
	{
		if (tmp->x == i && tmp->y == j)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_ennemies_on_player(t_data *s)
{
	if (__is_ennemie__(s, s->map->player_y, s->map->player_x))
		s->map->pv -= DAMAGE_PER_ENNEMIE;
}

char	*__get_ennemie_text__(t_data *s, int i, int j)
{
	t_ennemies	*tmp;

	tmp = s->ennemies;
	while (tmp)
	{
		if (tmp->x == i && tmp->y == j)
			return (tmp->texture);
		tmp = tmp->next;
	}
	return (NULL);
}
