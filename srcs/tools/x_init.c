#include "../../includes/so_long.h"

void	set_x_map(t_data *data)
{
	data->map->height = 0;
	data->map->width = 0;
	data->map->collec = 0;
	data->map->grass = 0;
	data->map->exit = 0;
	data->map->player = 0;
	data->map->player_x = 0;
	data->map->player_y = 0;
	data->map->player_dir = 0;
	data->map->pv = 0;
	data->map->mouv = 0;
	data->map->variable = 0;
}

void	set_x_mlx(t_data *data)
{
	data->mlx->mlx = 0;
	data->mlx->win = 0;
	data->mlx->addr = 0;
	data->mlx->img = 0;
	data->mlx->height = 0;
	data->mlx->width = 0;
	data->mlx->size_line = 0;
	data->mlx->bits_per_pixel = 0;
	data->mlx->endian = 0;
	data->ennemies = NULL;
}

t_data *x(void)
{
	static t_data *data;

	if (!data)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (NULL);
		data->mlx = malloc(sizeof(t_mlx));
		if (!data->mlx)
			return (NULL);
		data->map = malloc(sizeof(t_map));
		if (!data->map)
			return (NULL);
		set_x_map(data);
		set_x_mlx(data);
	}
	return (data);
}

void ft_x_init()
{
	t_mlx img;

	img.img = mlx_xpm_file_to_image(x()->mlx->mlx, WALL, &img.height, &img.width);
	if (RESOLUTION_AUTO == FALSE && WIND_RESOLUTION_X >= (30 + (PV + 1 / 2) * 30) && WIND_RESOLUTION_Y > 70 + x()->map->height)
	{
		x()->mlx->height = WIND_RESOLUTION_Y;
		x()->mlx->width = WIND_RESOLUTION_X;
	}
	else
	{
		x()->mlx->height = (x()->map->height * img.height) + 70;
		x()->mlx->width = max(x()->map->width * img.width, (30 + (PV + 1 / 2) * 30));
	}
	mlx_destroy_image(x()->mlx->mlx, img.img);
	x()->map->player_dir = 1;
	x()->map->pv = PV;
}