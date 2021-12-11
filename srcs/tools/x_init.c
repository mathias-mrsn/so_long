#include "../../includes/so_long.h"

static void	__set_x_map__(t_data *data)
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

static void	__set_x_mlx__(t_data *data)
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
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = malloc(sizeof(t_mlx));
	if (!data->mlx)
		return (NULL);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (NULL);
	__set_x_map__(data);
	__set_x_mlx__(data);
	return (data);
}

void ft_x_init(t_data *s)
{
	t_mlx img;

	img.img = mlx_xpm_file_to_image(s->mlx->mlx, WALL, &img.height, &img.width);
	if (BONUS)
	{
		s->mlx->height = WINDOWS_Y;
		s->mlx->width = __max(WINDOWS_X, (30 + (PV + 1 / 2) * 30));
	}
	else
	{
		s->mlx->height = (s->map->height * img.height);
		s->mlx->width = s->map->width * img.width;
	}
	mlx_destroy_image(s->mlx->mlx, img.img);
	s->map->player_dir = 1;
	s->map->pv = PV;
}