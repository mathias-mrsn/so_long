/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:00:16 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/12 12:31:53 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	__move_left__(t_data *s)
{
	if (s->map->map[s->map->player_x][s->map->player_y + 1] != '1')
	{
		s->map->player_y++;
		s->map->mouv++;
		if (!BONUS)
			__printf("You made %5d movements\n", s->map->mouv);
		ft_collectible(s);
	}
	s->map->player_dir = 2;
}

static void	__move_right__(t_data *s)
{
	if (s->map->map[s->map->player_x][s->map->player_y - 1] != '1')
	{
		s->map->player_y--;
		s->map->mouv++;
		if (!BONUS)
			__printf("You made %5d movements\n", s->map->mouv);
		ft_collectible(s);
	}
	s->map->player_dir = 0;
}

static void	__move_up__(t_data *s)
{
	if (s->map->map[s->map->player_x - 1][s->map->player_y] != '1')
	{
		s->map->player_x--;
		s->map->mouv++;
		if (!BONUS)
			__printf("You made %5d movements\n", s->map->mouv);
		ft_collectible(s);
	}
	s->map->player_dir = 1;
}

static void	__move_down__(t_data *s)
{
	if (s->map->map[s->map->player_x + 1][s->map->player_y] != '1')
	{
		s->map->player_x++;
		s->map->mouv++;
		if (!BONUS)
			__printf("You made %5d movements\n", s->map->mouv);
		ft_collectible(s);
	}
	s->map->player_dir = 3;
}

int	key_hook(int key_code, t_data *s)
{
	if (key_code == KEY_LEFT)
		__move_left__(s);
	else if (key_code == KEY_RIGHT)
		__move_right__(s);
	else if (key_code == KEY_UP)
		__move_up__(s);
	else if (key_code == KEY_DOWN)
		__move_down__(s);
	else if (key_code == KEY_ESC)
	{
		__printf("Escape key was pressed, good bye see you soon !\n");
		ft_quit("0123", NULL, s);
	}
	ft_ennemies_on_player(s);
	return (__SUCCESS);
}
