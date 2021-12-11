#include "../../includes/so_long.h"

static int ft_print_map(const struct s_texture textfile[5], t_data *s)
{
	const struct s_texture playerfile[5] = {{'0', PLAYER_LEFT}, {'0', PLAYER_BACK}, {'0', PLAYER_RIGHT}, {'0', PLAYER_FRONT}};
	int i;
	int j;

	i = 0;
	while (s->map->map[i])
	{
		j = 0;
		while (s->map->map[i][j])
		{
			if (i == s->map->player_x && j == s->map->player_y)
				__put_texture__(i, j, s, __get_img__(s, playerfile[s->map->player_dir].filepath));
			else if (__is_ennemie__(s, j, i))
				__put_texture__(i, j, s, __get_img__(s, __get_ennemie_text__(s, j, i)));
			else
				__put_texture__(i, j, s, __get_img__(s, __get_texture__(s, textfile, s->map->map[i][j])));
			j++;
		}
		i++;
	}
	return (0);
}

static void ft_print_pv(t_data *s)
{
	int i;
	int pixel_space;

	pixel_space = 0;
	i = 0;
	if (!BONUS)
		return ;
	while (i <= PV)
	{
		if (s->map->pv > i)
		{
			if (s->map->pv - 1 == i)
				__put_img_to_win__(s, pixel_space + 15, 15, __get_img__(s, HALF_HEART));
			else
				__put_img_to_win__(s, pixel_space + 15, 15, __get_img__(s, FULL_HEART));
		}
		else
			__put_img_to_win__(s, pixel_space + 15, 15, __get_img__(s, EMPTY_HEART));
		i += 2;
		pixel_space += 30;
	}
}

static void	__print_score__(t_data *s)
{
	char *score;
	char *nbr;

	if (!BONUS)
		return ;
	nbr = __itoa(s->map->mouv);
	score = __strjoin("Moves : ", nbr);
	mlx_string_put(s->mlx->mlx, s->mlx->win, 15, 50, 0xFFFFFF, score);
	free(nbr);
	free(score);
}

int ft_display_hub(t_data *s)
{
	const struct s_texture textfile[5] = {{'1', WALL}, {'0', GRASS}, {'C', COLLECTIBLE_1}, {'E', EXIT}};
	ft_print_map(textfile, s); //Done
	ft_print_pv(s); //Done
	ft_move_ennemies(s);
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, s->mlx->img, 0, 0);
	__print_score__(s);
	ft_collectible(s);
	ft_is_done(s);
	if (!(s->map->variable % 4))
		ft_ennemies_on_player(s);
	s->map->variable++;
	return (0);
}