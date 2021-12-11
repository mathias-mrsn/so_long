/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:53:54 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/11 18:53:55 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	__pixel_on_img__(t_mlx *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	__put_img_to_win__(t_data *s, int a, int b, t_mlx img)
{
	const int	*color = (int *)mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.size_line, &img.endian);
	double		i;
	double		j;

	i = 0.0;
	while (i < img.height)
	{
		j = 0.0;
		while (j < img.width)
		{
			__pixel_on_img__(s->mlx, a + i, b + j,
				color[(int)j * img.height + (int)i]);
			j += 1.0;
		}
		i += 1.0;
	}
	mlx_destroy_image(s->mlx->mlx, img.img);
}

void	__put_texture__(int a, int b, t_data *s, t_mlx img)
{
	int				*color;
	const double	ratio_x = (double)s->mlx->width / s->map->width;
	const double	ratio_y = (double)
		(s->mlx->height - STATUS_BAR) / s->map->height;
	double			i;
	double			j;

	color = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.size_line, &img.endian);
	i = 0.0;
	while (i < ratio_x)
	{
		j = 0.0;
		while (j < ratio_y)
		{
			__pixel_on_img__(s->mlx, b * ratio_x + i,
				(a * ratio_y) + j + STATUS_BAR, color[(int)
				(j / (ratio_y / img.height)) *img.height + (int)
				(i / (ratio_x / img.width))]);
			j += img.height / __fmax__(img.height, ratio_y);
		}
		i += img.width / __fmax__(img.height, ratio_y);
	}
	mlx_destroy_image(s->mlx->mlx, img.img);
}

char	*__get_texture__(t_data *s, const struct s_texture textfile[5], char c)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (textfile[i].c == c)
		{
			if (c == 'C')
			{
				if (!BONUS || s->map->variable % COLLEC_REFRESH_TIME < 5)
					return (COLLECTIBLE_1);
				return (COLLECTIBLE_2);
			}
			return (textfile[i].filepath);
		}
		i++;
	}
	return (NULL);
}

t_mlx	__get_img__(t_data *s, char *pathfile)
{
	t_mlx	img;

	img.img = mlx_xpm_file_to_image(s->mlx->mlx,
			pathfile, &img.height, &img.width);
	img.addr = mlx_get_data_addr(s->mlx->mlx,
			&img.bits_per_pixel, &img.size_line, &img.endian);
	return (img);
}
