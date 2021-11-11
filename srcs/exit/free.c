#include "../../includes/so_long.h"

void free_map(void)
{
	int i;

	i = x()->map->height;
	while (--i >= 0)
	{
		free(x()->map->map[i]);
	}
	free(x()->map->map);
}

void free_struct(void)
{
	free(x()->map);
	free(x()->mlx);
	free(x());
}

void	close_window(void)
{
	if(x()->mlx->img)
		mlx_destroy_image(x()->mlx->mlx, x()->mlx->img);
	if(x()->mlx->win)
		mlx_destroy_window(x()->mlx->mlx, x()->mlx->win);
	mlx_destroy_display(x()->mlx->mlx);
	free(x()->mlx->mlx);
}

void	free_ennemies(void)
{
	t_ennemies *tmp;
	t_ennemies *del;

	tmp = x()->ennemies;
	while(tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del->texture);
		free(del);
	}
}