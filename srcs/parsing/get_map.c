/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:58:46 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/11 18:58:47 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	__file_height__(char *str)
{
	int		fd;
	char	c;
	int		len;

	len = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			len++;
	close(fd);
	return (len + 1);
}

void	ft_get_map(t_data *s, char **argv)
{
	char	*str;
	size_t	i;
	size_t	fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_quit("3", "Error :\ncouldn't open file", s);
	s->map->map = malloc(sizeof(char *) * (__file_height__(argv[1]) + 1));
	if (!s->map->map)
		ft_quit("03", "Error :\nmemory errors", s);
	str = __gnl(fd);
	while (str)
	{
		s->map->map[i++] = str;
		s->map->height++;
		str = __gnl(fd);
	}
	s->map->map[i] = NULL;
	close(fd);
}
