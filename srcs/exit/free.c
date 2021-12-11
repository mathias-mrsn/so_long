/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:56:07 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/11 18:56:08 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(t_data *s)
{
	int	i;

	i = s->map->height;
	while (--i >= 0)
		free(s->map->map[i]);
	free(s->map->map);
}

static void	free_struct(t_data *s)
{
	free(s->map);
	free(s->mlx);
	free(s);
}

static void	close_window(t_data *s)
{
	if (s->mlx->img)
		mlx_destroy_image(s->mlx->mlx, s->mlx->img);
	if (s->mlx->win)
		mlx_destroy_window(s->mlx->mlx, s->mlx->win);
	free(s->mlx->mlx);
}

static void	free_ennemies(t_data *s)
{
	t_ennemies	*tmp;
	t_ennemies	*del;

	tmp = s->ennemies;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del->texture);
		free(del);
	}
}

int	ft_quit(char *str, char *text, t_data *s)
{
	static void		(*f[4])() = {free_map,
		close_window, free_ennemies, free_struct};
	char			c;

	__print_end__(text, s);
	while (*str)
	{
		c = *str;
		if (c >= '0' && c <= '3')
			(f[c - 48])(s);
		str++;
	}
	exit(0);
}
