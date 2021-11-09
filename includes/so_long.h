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

# define GRASS "texture/grass.xpm"
# define WALL "texture/wall.xpm"
# define COLLECTIBLE_1 "texture/collectible_1.xpm"
# define COLLECTIBLE_2 "texture/collectible_2.xpm"
# define PLAYER "texture/player.xpm"
# define EXIT "texture/exit.xpm"
# define FULL_HEART "texture/full_heart.xpm"
# define HALF_HEART "texture/half_heart.xpm"
# define EMPTY_HEART "texture/empty_heart.xpm"
# define ENNEMIE "texture/ennemie.xpm"

# define TRUE 1
# define FALSE 0

/*	
	ENNEMIES SETTINGS
*/

# define ENNEMIES_SPEED 20 //smaller is the number faster will be the ennemies speed.
# define DAMAGE_PER_ENNEMIE 1;

# define PV 9

# define WIND_RESOLUTION_X 106
# define WIND_RESOLUTION_Y 76
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

	int		coll_sprite
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
	int		texture_height;
	int		texture_width;
	int		align;
}				t_mlx;

typedef struct s_ennemies
{
	int	x;
	int	y;
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

#endif