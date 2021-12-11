/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:58:12 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/11 18:58:13 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_is_rectangle(t_data *s)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s->map->map[0]);
	i = 1;
	while (s->map->map[i])
	{
		if (ft_strlen(s->map->map[i]) != len)
		{
			if (i == 1 && s->map->map[2] && len != ft_strlen(s->map->map[2]))
				print_quit("Error :\nThe map isn't a rectangle\n",
					"03", i - 1, s);
			else
				print_quit("Error :\nThe map isn't a rectangle\n", "03", i, s);
		}
		i++;
	}
	s->map->width = len;
	if (s->map->width < 3 || s->map->height < 3)
		ft_quit("14", "Error :\nMap is too small\n", s);
}

static void	ft_check_exit(t_data *s)
{
	if (s->map->exit < 1)
		ft_quit("03", "Error :\nNo exit on the map\n", s);
	if (s->map->player < 1)
		ft_quit("03", "Error :\nNo player on the map\n", s);
	if (s->map->player > 1)
		ft_quit("03", "Error :\nToo many players on the map\n", s);
	if (s->map->collec < 1)
		ft_quit("03", "Error :\nNo collectible on the map\n", s);
}

static void	ft_is_correct_map(t_data *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s->map->map[i])
	{
		j = 0;
		while (s->map->map[i][j])
		{
			if (s->map->map[i][j] == 'C')
				s->map->collec++;
			if (s->map->map[i][j] == 'P')
				s->map->player++;
			if (s->map->map[i][j] == 'E')
				s->map->exit++;
			if (s->map->map[i][j] == '0')
				s->map->grass++;
			if (!ft_is_charset(s->map->map[i][j], ELEM_MAP))
				print_quit("Error :\nInvalid element ont the map\n", "03", i, s);
			j++;
		}
		i++;
	}
	ft_check_exit(s);
}

static void	ft_is_surrended_by_walls(t_data *s)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < s->map->height)
		if (s->map->map[i][0] != '1')
			print_quit("Error :\nIsn't surrended by walls\n", "03", i, s);
	while (++j < s->map->width)
		if (s->map->map[0][j] != '1')
			print_quit("Error :\nIsn't surrended by walls\n", "03", 0, s);
	while (--i > -1)
		if (s->map->map[i][j - 1] != '1')
			print_quit("Error :\nIsn't surrended by walls\n", "03", i, s);
	while (--i > -1)
		if (s->map->map[s->map->height - 1][j] != '1')
			print_quit("Error :\nIsn't surrended by walls\n",
				"03", s->map->height - 1, s);
}

void	ft_map_check(t_data *s, int argc, char **argv)
{
	size_t	file_name_len;
	int		fd;

	if (argc < 2)
		ft_quit("3", "Error :\nNo argument\n", s);
	if (argc > 2)
		ft_quit("3", "Error :\nToo many arguments\n", s);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_quit("3", "Error :\nNo such file or directory\n", s);
	close(fd);
	file_name_len = strlen(argv[1]);
	if (__strncmp(&argv[1][file_name_len - 4], ".ber", 4))
		ft_quit("3", "Error :\nBad file extension\n", s);
	ft_get_map(s, argv);
	ft_is_correct_map(s);
	ft_is_rectangle(s);
	ft_is_surrended_by_walls(s);
	ft_get_player_position(s->map);
	ft_add_ennemies(s);
}
