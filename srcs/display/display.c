#include "../../includes/so_long.h"

int ft_print_map(const struct s_texture textfile[5], t_mlx *mlx)
{
	const struct s_texture playerfile[5] = {{'0', PLAYER_LEFT}, {'0', PLAYER_BACK}, {'0', PLAYER_RIGHT}, {'0', PLAYER_FRONT}};
	size_t i;
	size_t j;

	i = 0;
	while (x()->map->map[i])
	{
		j = 0;
		while (x()->map->map[i][j])
		{
			if (i == x()->map->player_x && j == x()->map->player_y)
				ft_put_texture(i, j, mlx, ft_get_img(playerfile[x()->map->player_dir].filepath)); // i == y and j == x
			else if (ft_is_ennemies(j, i))
				ft_put_texture(i, j, mlx, ft_get_img(ft_get_ennemie_text(j, i)));
			else
				ft_put_texture(i, j, mlx, ft_get_img(ft_get_texture(textfile, x()->map->map[i][j])));
			j++;
		}
		i++;
	}
	return (0);
}

void ft_print_pv()
{
	int i;
	int pixel_space;

	pixel_space = 0;
	i = 0;
	while (i <= PV)
	{
		if (x()->map->pv > i)
		{
			if (x()->map->pv - 1 == i)
				ft_put_img_to_win(x()->mlx, pixel_space + 15, 15, ft_get_img(HALF_HEART));
			else
				ft_put_img_to_win(x()->mlx, pixel_space + 15, 15, ft_get_img(FULL_HEART));
		}
		else
			ft_put_img_to_win(x()->mlx, pixel_space + 15, 15, ft_get_img(EMPTY_HEART));
		i += 2;
		pixel_space += 30;
	}
}

void	ft_print_score()
{
	char *score;
	char *nbr;

	nbr = ft_itoa(x()->map->mouv);
	score = ft_strcat("Moves : ", nbr);
	mlx_string_put(x()->mlx->mlx, x()->mlx->win, 15, 50, 0xFFFFFF, score);
	free(nbr);
	free(score);
}

void ft_display_hub(t_mlx *img)
{
	const struct s_texture textfile[5] = {{'1', WALL}, {'0', GRASS}, {'C', COLLECTIBLE_1}, {'E', EXIT}};
	ft_print_map(textfile, img);
	ft_print_pv();
	ft_move_ennemies();
	mlx_put_image_to_window(img->mlx, img->win, x()->mlx->img, 0, 0);
	ft_print_score();
	ft_collectible();
	ft_is_done();
	if (!(x()->map->variable % 4))
		ft_ennemies_on_player();
	x()->map->variable++;
}