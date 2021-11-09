#ifndef SO_LONG_H
# define SO_LONG_H

# define ELEM_MAP "01ECP"

# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
#include  <errno.h>
# include <math.h>
# include <stdio.h>

# define GRASS 			"texture/grass.xpm"
# define WALL 			"texture/wall.xpm"
# define COLLECTIBLE_1 	"texture/collectible_1.xpm"
# define COLLECTIBLE_2 	"texture/collectible_2.xpm"
# define PLAYER_FRONT 	"texture/player_front.xpm"
# define PLAYER_BACK 	"texture/player_back.xpm"
# define PLAYER_LEFT 	"texture/player_left.xpm"
# define PLAYER_RIGHT 	"texture/player_right.xpm"
# define EXIT 			"texture/exit.xpm"
# define FULL_HEART 	"texture/full_heart.xpm"
# define HALF_HEART 	"texture/half_heart.xpm"
# define EMPTY_HEART 	"texture/empty_heart.xpm"
# define ENNEMIE_1 		"texture/ennemie_1.xpm"
# define ENNEMIE_2 		"texture/ennemie_2.xpm"


# define TRUE 1
# define FALSE 0

/*	
	ENNEMIES SETTINGS
*/

# define ENNEMIES_SPEED 30 //smaller is the number faster will be the ennemies speed.
# define DAMAGE_PER_ENNEMIE 1;

# define PV 9

# define WIND_RESOLUTION_X 1500
# define WIND_RESOLUTION_Y 300
# define RESOLUTION_AUTO FALSE

typedef struct	s_map
{
	char	**map;
	int		height;
	int		width;
	int		collec;
	int		grass;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
	int		player_dir;	
	int		pv;
	int		mouv;

	int		coll_sprite;
}				t_map;

typedef	struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
}				t_mlx;

typedef struct s_ennemies
{
	int					x;
	int					y;
	char 				*texture;
	struct s_ennemies	*next;
}				t_ennemies;


typedef struct s_texture
{
	char	c;
	char	*filepath;
}			t_texture;

typedef struct s_data
{
	struct s_mlx *mlx;
	struct s_map *map;
	struct s_ennemies *ennemies;
	
}				t_data;

t_data *x(void);
void ft_create_ennemies(int i, int j, char *file);
void ft_print_list();
void free_map(void);
void free_struct(void);
int quit_parsing(char *str, int print_map_error, int ord, int abs);
int ft_file_height(char *str);
int ft_get_map(t_map *map, int argc, char **argv);
int ft_is_rectangle(t_map *map);
int ft_check_exit(t_map *map);
int ft_is_correct_map(t_map *map);
int ft_is_surrended_by_walls(t_map *map);
void ft_get_player_position(t_map *map);
void ft_add_ennemies(t_map *map);
int ft_map_check(t_map *map, int argc, char **argv);
int get_t(int trgb);
int get_r(int trgb);
int get_g(int trgb);
int get_b(int trgb);
char *ft_strcat(const char *s1, const char *s2);
int ft_is_ennemies(int i, int j);
void ft_ennemies_on_player(void);
char *ft_get_ennemie_text(int i, int j);
void ft_ennemies_up(int *i, int *y);
void ft_ennemies_down(int *i, int *y);
void ft_ennemies_left(int *i, int *y);
void ft_ennemies_right(int *i, int *y);
void ft_move_ennemies();
void put_pixel_on_img(t_mlx *img, int x, int y, int color);
int ft_put_img_to_win(t_mlx *mlx, int a, int b, t_mlx img);
void ft_put_texture(int a, int b, t_mlx *mlx, t_mlx img);
char *ft_get_texture(const struct s_texture textfile[5], char c);
t_mlx ft_get_img(char *pathfile);
int ft_print_map(const struct s_texture textfile[5], t_mlx *mlx);
int max(int x, int y);
void ft_x_init();
void ft_move_up();
void ft_move_down();
void ft_move_left();
void ft_move_right();
void ft_is_done(void);
void ft_collect_collectible(void);
void ft_print_pv();
void ft_display_hub(t_mlx *img);
int key_hook(int key_code);
int main(int argc, char **argv);
t_ennemies *ft_create_elem(int a,int b,char *file);

#endif