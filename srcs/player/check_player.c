/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:00:20 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/11 19:00:21 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_is_done(t_data *s)
{
	if (s->map->pv < 1)
		ft_quit("0123", "You died", s);
	if (s->map->map[s->map->player_x][s->map->player_y] == 'E'
		&& s->map->collec == 0)
		ft_quit("0123", "Congrats", s);
}

void	ft_collectible(t_data *s)
{
	if (s->map->map[s->map->player_x][s->map->player_y] == 'C')
	{
		s->map->collec--;
		s->map->map[s->map->player_x][s->map->player_y] = '0';
	}
}
