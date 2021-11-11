#include "../../includes/so_long.h"

int key_hook(int key_code)
{
	if (key_code == 97)
		ft_move_left();
	else if (key_code == 100)
		ft_move_right();
	else if (key_code == 119)
		ft_move_up();
	else if (key_code == 115)
		ft_move_down();
	else if (key_code == 65307)
	{
		ft_quit("0123", "Error :\nSee you soon !");
	}
	ft_ennemies_on_player();
	return (0);
}

void ft_move_left()
{
	if (x()->map->map[x()->map->player_x][x()->map->player_y - 1] != '1')
	{
		x()->map->player_y--;
		x()->map->mouv++;
		x()->map->player_dir = 0;
		ft_collectible();
	}
}

void ft_move_right()
{
	if (x()->map->map[x()->map->player_x][x()->map->player_y + 1] != '1')
	{
		x()->map->player_y++;
		x()->map->mouv++;
		x()->map->player_dir = 2;
		ft_collectible();
	}
}

void ft_move_up()
{
	if (x()->map->map[x()->map->player_x - 1][x()->map->player_y] != '1')
	{
		x()->map->player_x--;
		x()->map->mouv++;
		x()->map->player_dir = 1;
		ft_collectible();
	}
}

void ft_move_down()
{
	if (x()->map->map[x()->map->player_x + 1][x()->map->player_y] != '1')
	{
		x()->map->player_x++;
		x()->map->mouv++;
		x()->map->player_dir = 3;
		ft_collectible();
	}
}
