#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	int i;
	int j;

	ft_map_check(x()->map, argc, argv);
	x()->mlx->mlx = mlx_init();
	mlx_do_key_autorepeaton(x()->mlx->mlx);
	ft_x_init();
	x()->mlx->win = mlx_new_window(x()->mlx->mlx, x()->mlx->width, x()->mlx->height, "so_long");
	x()->mlx->img = mlx_new_image(x()->mlx->mlx, x()->mlx->width, x()->mlx->height);
	x()->mlx->addr = mlx_get_data_addr(x()->mlx->img, &x()->mlx->bits_per_pixel, &x()->mlx->size_line, &x()->mlx->endian);
	ft_display_hub(x()->mlx);
	mlx_hook(x()->mlx->win, 2, (1L << 0), key_hook, NULL);
	mlx_hook(x()->mlx->win, 3, (1L << 1), NULL, NULL);
	mlx_hook(x()->mlx->win, 17, (0L), &ft_red_cross, NULL);
	mlx_loop_hook(x()->mlx->mlx, ft_display_hub, x()->mlx);
	mlx_loop(x()->mlx->mlx);
	return (0);
}


