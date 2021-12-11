/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:49:23 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/11 19:01:41 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*s;

	s = x();
	ft_map_check(s, argc, argv);
	s->mlx->mlx = mlx_init();
	mlx_do_key_autorepeaton(s->mlx->mlx);
	ft_x_init(s);
	s->mlx->win = mlx_new_window(s->mlx->mlx,
			s->mlx->width, s->mlx->height, "so_long");
	s->mlx->img = mlx_new_image(s->mlx->mlx,
			s->mlx->width, s->mlx->height);
	s->mlx->addr = mlx_get_data_addr(s->mlx->img,
			&s->mlx->bits_per_pixel, &s->mlx->size_line, &s->mlx->endian);
	ft_display_hub(s);
	mlx_hook(s->mlx->win, 2, (1L << 0), key_hook, s);
	mlx_hook(s->mlx->win, 3, (1L << 1), NULL, NULL);
	mlx_hook(s->mlx->win, RED_CROSS, (0L), &red_cross, s);
	mlx_loop_hook(s->mlx->mlx, &ft_display_hub, s);
	mlx_loop(s->mlx->mlx);
	return (__SUCCESS);
}
