#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mlx/mlx.h"

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b); // (11111111 = T, 11111111 = R ... x2 pour 32 bits)
}

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24)); // (Retourner le point commun entre le nombre et 11111111 decaller n bits)
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
    return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}

//To do, learn how to use xpm files then create program to print a texture