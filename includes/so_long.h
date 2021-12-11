/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:16:48 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/11 19:16:49 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"

/*
	TEXTURE
*/

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

/*
	KEY MAPPING
*/

# if defined(__APPLE__) && defined(__MACH__)
#  define KEY_ESC		53
#  define KEY_UP		13
#  define KEY_RIGHT	0
#  define KEY_DOWN		1
#  define KEY_LEFT		2
#  define RED_CROSS	17
# else
#  define KEY_ESC		65307
#  define KEY_UP		119
#  define KEY_RIGHT	97
#  define KEY_DOWN		115
#  define KEY_LEFT		100
#  define RED_CROSS	33
# endif

# define TRUE 1
# define FALSE 0
# define ELEM_MAP "01ECP"

/*	
	ENNEMIES SETTINGS
*/

# define ENNEMIES_SPEED 30
# define DAMAGE_PER_ENNEMIE 1;

/*
	PLAYER SETTINGS
*/

# define PV 9

/*
	WINDOWS SETTINGS
*/

# define WINDOWS_X 800
# define WINDOWS_Y 800

/*
	BONUS SETTINGS
*/

# ifndef BONUS
#  define BONUS 1
# endif

# if (BONUS == 1)
#  define STATUS_BAR 70
# else
#  define STATUS_BAR 0
# endif

/*
	COLLECTIBLE
*/

# define COLLEC_REFRESH_TIME 20

typedef struct s_map
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
	int		variable;
}				t_map;

typedef struct s_mlx
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
	char				*texture;
	struct s_ennemies	*next;
}				t_ennemies;

typedef struct s_texture
{
	char	c;
	char	*filepath;
}			t_texture;

typedef struct s_data
{
	struct s_mlx		*mlx;
	struct s_map		*map;
	struct s_ennemies	*ennemies;
}				t_data;

int		main(int argc, char **argv);

/*
	DISPLAY
*/

int		ft_display_hub(t_data *s);
void	__pixel_on_img__(t_mlx *img, int x, int y, int color);
void	__put_img_to_win__(t_data *s, int a, int b, t_mlx img);
void	__put_texture__(int a, int b, t_data *s, t_mlx img);
char	*__get_texture__(t_data *s, const struct s_texture textfile[5], char c);
t_mlx	__get_img__(t_data *s, char *pathfile);
char	*__get_ennemie_text__(t_data *s, int i, int j);

/*
	DISPLAY TOOLS
*/

void	ft_is_done(t_data *s);
void	ft_collectible(t_data *s);

/*
	EVENTS
*/

int		red_cross(t_data *s);
int		key_hook(int key_code, t_data *s);

/*
	COLOR TOOLS
*/

int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/*
	ENNEMIES
*/

void	ft_create_ennemies(t_data *s, int i, int j, char *file);
int		__is_ennemie__(t_data *s, int i, int j);
void	ft_ennemies_on_player(t_data *s);
void	ft_move_ennemies(t_data *s);
void	ft_add_ennemies(t_data *s);

/*
	TOOLS
*/

int		max(int x, int y);
t_data	*x(void);
void	ft_x_init(t_data *s);
void	__print_end__(char *str, t_data *s);
float	__fmax__(float a, float b);
char	*ft_strcat(const char *s1, const char *s2);

/*
	EXIT FUNCTIONS
*/

int		print_quit(char *str, char *free, int abs, t_data *s);
int		ft_quit(char *str, char *text, t_data *s);

/*
	PARSING
*/

void	ft_map_check(t_data *s, int argc, char **argv);
void	ft_get_map(t_data *s, char **argv);
void	ft_get_player_position(t_map *map);

#endif