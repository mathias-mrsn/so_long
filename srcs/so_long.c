#include "../mlx/mlx.h"
#include "../includes/so_long.h"

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
	}
	return (data);
}

t_ennemies *ft_create_elem(int a, int b, char *file)
{
	t_ennemies *new;

	new = malloc(sizeof(t_ennemies));
	if (!new)
		return (NULL);
	new->x = a;
	new->y = b;
	new->next = NULL;
	new->texture = ft_strdup(file);
	return (new);
}

void ft_create_ennemies(int i, int j, char *file)
{
	t_ennemies *new;

	if (!x()->ennemies)
		x()->ennemies = ft_create_elem(i, j, file);
	else
	{
		new = ft_create_elem(i, j, file);
		new->next = x()->ennemies;
		x()->ennemies = new;
	}
}

void ft_print_list()
{
	t_ennemies *tmp = x()->ennemies;

	while (tmp)
	{
		printf("X = %d | Y = %d\n", tmp->x, tmp->y);
		tmp = tmp->next;
	}
}

long ft_rand(int len_max)
{
	int fd;
	int i;
	long res;
	char str[7];

	res = 0;
	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		return (0);
	if (read(fd, str, 9))
	{
		str[6] = '\0';
		i = 6;
		while (--i > 0)
		{
			res *= 10;
			res += str[i];
		}
	}
	close(fd);
	if (res < 0)
		res *= -1;
	return (res % len_max);
}

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

int quit_parsing(char *str, int print_map_error, int ord, int abs)
{
	size_t index;
	size_t j;

	index = 0;
	printf("Error : \"%s\"\n", str);
	while (index < x()->map->height && print_map_error == 1)
	{
		j = 0;
		printf("line --> %-5zu : \"", index);
		while (x()->map->map[index][j])
		{
			if (ord == index && abs == j || ord == index && abs == -1)
				printf("\033[0;31m%c\033[0m", x()->map->map[index][j]);
			else
				printf("\033[0;32m%c\033[0m", x()->map->map[index][j]);
			j++;
		}
		printf("\"\n");
		index++;
	}
	free_map();
	free_struct();
	exit(0);
	return (0);
}

int ft_file_height(char *str)
{
	int fd;
	char c;
	int len;

	len = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			len++;
	close(fd);
	return (len + 1);
}

int ft_get_map(t_map *map, int argc, char **argv)
{
	char *str;
	size_t i;
	size_t fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (quit_parsing(strerror(errno), 0, -1, -1), 1);
	map->map = malloc(sizeof(char *) * (ft_file_height(argv[1]) + 1));
	if (!map->map)
		return (quit_parsing("malloc error", 0, -1, -1), 1);
	str = get_next_line(fd);
	while (str)
	{
		map->map[i++] = str;
		map->height++;
		str = get_next_line(fd);
	}
	map->map[i] = NULL;
	close(fd);
	return (0);
}

int ft_is_rectangle(t_map *map)
{
	size_t len;
	size_t i;

	len = ft_strlen(map->map[0]);
	i = 1;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != len)
		{
			if (i == 1 && map->map[2] && len != ft_strlen(map->map[2]))
				return (quit_parsing("the map isn't a rectangle", 1, i - 1, -1), 1);
			else
				return (quit_parsing("the map isn't a rectangle", 1, i, -1), 1);
		}
		i++;
	}
	map->width = len;
	if (x()->map->width < 3 || x()->map->height < 3)
		return (quit_parsing("map too small", 0, -1, -1), 1);
	return (0);
}

int ft_check_exit(t_map *map)
{
	// if (x()->map->width < 3 || x()->map->height < 3)
	// 	return(quit_parsing("map too small", 0, -1, -1), 1);
	if (x()->map->exit < 1)
		return (quit_parsing("no exit on the map", 0, -1, -1), 1);
	if (x()->map->player < 1)
		return (quit_parsing("no player on the map", 0, -1, -1), 1);
	if (x()->map->collec < 1)
		return (quit_parsing("no collectible on the map", 0, -1, -1), 1);
	return (0);
}

int ft_is_correct_map(t_map *map)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (x()->map->map[i])
	{
		j = 0;
		while (x()->map->map[i][j])
		{
			if (x()->map->map[i][j] == 'C')
				map->collec++;
			if (x()->map->map[i][j] == 'P')
				map->player++;
			if (x()->map->map[i][j] == 'E')
				map->exit++;
			if (x()->map->map[i][j] == '0')
				map->grass++;
			if (!ft_is_charset(x()->map->map[i][j], ELEM_MAP))
				return (quit_parsing("Invalide elem on the map", 1, i, j), 1);
			j++;
		}
		i++;
	}
	ft_check_exit(map);
	return (0);
}

int ft_is_surrended_by_walls(t_map *map)
{
	size_t i;
	size_t j;

	i = -1;
	j = -1;
	while (++i < map->height)
		if (map->map[i][0] != '1')
			return (quit_parsing("isn't surrended by walls", 1, i, 0), 1);
	while (++j < map->width)
		if (map->map[0][j] != '1')
			return (quit_parsing("isn't surrended by walls", 1, 0, j), 1);
	while (--i > -1)
		if (map->map[i][j - 1] != '1')
			return (quit_parsing("isn't surrended by walls", 1, i, j - 1), 1);
	while (--i > -1)
		if (map->map[map->height - 1][j] != '1')
			return (quit_parsing("isn't surrended by walls", 1, map->height - 1, j), 1);
	return (0);
}

void ft_get_player_position(t_map *map)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (x()->map->map[i])
	{
		j = 0;
		while (x()->map->map[i][j])
		{
			if (x()->map->map[i][j] == 'P')
			{
				x()->map->player_x = i;
				x()->map->player_y = j;
				x()->map->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void ft_add_ennemies(t_map *map)
{
	if (x()->map->grass < 5)
		return;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (x()->map->map[i])
	{
		j = 0;
		while (x()->map->map[i][j])
		{
			if (x()->map->map[i][j] == '0' && !(i == x()->map->player_x && j == x()->map->player_y) && ft_rand(15) == 0) //Creer ft_rand
			{
				if (ft_rand(10) % 2)
					ft_create_ennemies(j, i, ENNEMIE_1);
				else
					ft_create_ennemies(j, i, ENNEMIE_2);
			}
			j++;
		}
		i++;
	}
	ft_print_list();
}

int ft_map_check(t_map *map, int argc, char **argv)
{
	size_t file_name_len;

	if (argc < 2)
		quit_parsing("map missing", 0, -1, -1);
	if (argc > 2)
		quit_parsing("too many arguments", 0, -1, -1);
	file_name_len = strlen(argv[1]);
	if (ft_strncmp(&argv[1][file_name_len - 4], ".ber", 4))
		quit_parsing("invalid file extention", 0, -1, -1);
	ft_get_map(map, argc, argv);
	ft_is_correct_map(map);
	ft_is_rectangle(map);
	ft_is_surrended_by_walls(map);
	ft_get_player_position(map);
	ft_add_ennemies(map);
	return (0);
}

int get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int get_b(int trgb)
{
	return (trgb & 0xFF);
}

char *ft_strcat(const char *s1, const char *s2)
{
	char *str;
	int i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (*s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int ft_is_ennemies(int i, int j)
{
	t_ennemies *tmp;

	tmp = x()->ennemies;
	while (tmp)
	{
		if (tmp->x == i && tmp->y == j)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void ft_ennemies_on_player(void)
{
	if (ft_is_ennemies(x()->map->player_y, x()->map->player_x))
		x()->map->pv -= DAMAGE_PER_ENNEMIE;
	return;
}

char *ft_get_ennemie_text(int i, int j)
{
	t_ennemies *tmp;

	tmp = x()->ennemies;
	while (tmp)
	{
		if (tmp->x == i && tmp->y == j)
			return (tmp->texture);
		tmp = tmp->next;
	}
	return (NULL);
}

void ft_ennemies_up(int *i, int *y)
{
	(*y)++;
	if (*y == x()->map->player_x && *i == x()->map->player_y)
		x()->map->pv -= DAMAGE_PER_ENNEMIE;
}

void ft_ennemies_down(int *i, int *y)
{
	(*y)--;
	if (*y == x()->map->player_x && *i == x()->map->player_y)
		x()->map->pv -= DAMAGE_PER_ENNEMIE;
}

void ft_ennemies_left(int *i, int *y)
{
	(*i)--;
	if (*y == x()->map->player_x && *i == x()->map->player_y)
		x()->map->pv -= DAMAGE_PER_ENNEMIE;
}

void ft_ennemies_right(int *i, int *y)
{
	(*i)++;
	if (*y == x()->map->player_x && *i == x()->map->player_y)
		x()->map->pv -= DAMAGE_PER_ENNEMIE;
}

void ft_move_ennemies()
{
	t_ennemies *tmp;
	int rand;

	printf("%d", rand);
	tmp = x()->ennemies;
	while (tmp)
	{
		rand = ft_rand(4);
		if (ft_rand(20) == 0)
		{
			if (rand == 0 && x()->map->map[tmp->y - 1][tmp->x] != '1' && !ft_is_ennemies(tmp->x, tmp->y - 1))
				ft_ennemies_down(&tmp->x, &tmp->y);
			else if (rand == 1 && x()->map->map[tmp->y + 1][tmp->x] != '1' && !ft_is_ennemies(tmp->x, tmp->y + 1))
				ft_ennemies_up(&tmp->x, &tmp->y);
			else if (rand == 2 && x()->map->map[tmp->y][tmp->x - 1] != '1' && !ft_is_ennemies(tmp->x - 1, tmp->y))
				ft_ennemies_left(&tmp->x, &tmp->y);
			else if (rand == 3 && x()->map->map[tmp->y][tmp->x + 1] != '1' && !ft_is_ennemies(tmp->x + 1, tmp->y))
				ft_ennemies_right(&tmp->x, &tmp->y);
		}
		tmp = tmp->next;
	}
}

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
				if (x()->map->coll_sprite % 2 == 1)
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

int max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
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

void ft_move_up()
{
	if (x()->map->map[x()->map->player_x - 1][x()->map->player_y] != '1')
	{
		x()->map->player_x--;
		x()->map->mouv++;
		x()->map->player_dir = 1;
	}
}

void ft_move_down()
{
	if (x()->map->map[x()->map->player_x + 1][x()->map->player_y] != '1')
	{
		x()->map->player_x++;
		x()->map->mouv++;
		x()->map->player_dir = 3;
	}
}

void ft_move_left()
{
	if (x()->map->map[x()->map->player_x][x()->map->player_y - 1] != '1')
	{
		x()->map->player_y--;
		x()->map->mouv++;
		x()->map->player_dir = 0;
	}
}

void ft_move_right()
{
	if (x()->map->map[x()->map->player_x][x()->map->player_y + 1] != '1')
	{
		x()->map->player_y++;
		x()->map->mouv++;
		x()->map->player_dir = 2;
	}
}

void ft_is_done(void)
{
	if (x()->map->pv < 1)
	{
		exit(0);
	}

	if (x()->map->map[x()->map->player_x][x()->map->player_y] == 'E' && x()->map->collec == 0)
	{
		mlx_destroy_window(x()->mlx->mlx, x()->mlx->win);
		printf("You did %d mouvements", x()->map->mouv);
		quit_parsing("Congrats", 0, -1, -1);
	}
}

void ft_collect_collectible(void)
{
	if (x()->map->map[x()->map->player_x][x()->map->player_y] == 'C')
	{
		x()->map->collec--;
		x()->map->map[x()->map->player_x][x()->map->player_y] = '0';
	}
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

void ft_display_hub(t_mlx *img)
{
	const struct s_texture textfile[5] = {{'1', WALL}, {'0', GRASS}, {'C', COLLECTIBLE_1}, {'E', EXIT}};
	ft_print_map(textfile, img);
	ft_print_pv();
	ft_move_ennemies();
	mlx_put_image_to_window(img->mlx, img->win, x()->mlx->img, 0, 0);
	mlx_string_put(x()->mlx->mlx, x()->mlx->win, 15, 50, 0xFFFFFF, ft_strcat("Moves : ", ft_itoa(x()->map->mouv)));
	ft_collect_collectible();
	ft_is_done();
	x()->map->coll_sprite++;
}

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
		mlx_destroy_window(x()->mlx->mlx, x()->mlx->win);
		quit_parsing("Exit", 0, -1, -1);
	}
	ft_ennemies_on_player();
}

int main(int argc, char **argv)
{
	int i;
	int j;

	if (!x())
		quit_parsing("memory errors", 0, -1, -1);
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
	mlx_hook(x()->mlx->win, 17, 0L, exit, NULL);
	mlx_loop_hook(x()->mlx->mlx, ft_display_hub, x()->mlx);
	mlx_loop(x()->mlx->mlx);
	free_map();
	free_struct();
	return (0);
}
