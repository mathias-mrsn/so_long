#include "../../includes/so_long.h"

void put_pixel_on_img(t_mlx *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int ft_put_img_to_win(t_mlx *mlx, int a, int b, t_mlx img)
{
	int *color;

	color = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);
	double i;
	double j;

	i = 0.0;
	while (i < img.height)
	{
		j = 0.0;
		while (j < img.width)
		{
			put_pixel_on_img(x()->mlx, a + i, b + j, color[(int)j * img.height + (int)i]);
			j += 1.0;
		}
		i += 1.0;
	}
	mlx_destroy_image(x()->mlx->mlx, img.img);
	return (0);
}

void ft_put_texture(int a, int b, t_mlx *mlx, t_mlx img)
{
	int *color;
	const double ratio_x = mlx->width / x()->map->width;
	const double ratio_y = (mlx->height - 70) / x()->map->height;
	double i;
	double j;

	color = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);
	i = 0.0;
	while (i < ratio_x)
	{
		j = 0.0;
		while (j < ratio_y)
		{
			put_pixel_on_img(x()->mlx, b * ratio_x + i, (a * ratio_y) + j + 70,
							 color[(int)(j / (ratio_y / img.height)) * img.height + (int)(i / (ratio_x / img.width))]);
			if (img.height > ratio_y)
				j += 1.0;
			else
				j += img.height / ratio_y;
		}
		if (img.width > ratio_x)
			i += 1.0;
		else
			i += img.width / ratio_x;
	}
	mlx_destroy_image(x()->mlx->mlx, img.img);
}

char *ft_get_texture(const struct s_texture textfile[5], char c)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (textfile[i].c == c)
		{
			if (c == 'C')
			{
				if (x()->map->variable % 10  < 5)
					return (COLLECTIBLE_1);
				return (COLLECTIBLE_2);
			}
			return (textfile[i].filepath);
		}
		i++;
	}
	return (NULL);
}

t_mlx ft_get_img(char *pathfile)
{
	t_mlx img;

	img.img = mlx_xpm_file_to_image(x()->mlx->mlx, pathfile, &img.height, &img.width);
	img.addr = mlx_get_data_addr(x()->mlx->mlx, &img.bits_per_pixel, &img.size_line, &img.endian);
	return (img);
}