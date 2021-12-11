/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:48:12 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 13:56:02 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

static t_file	*__ft_find_file__(t_file **mem, int fd)
{
	t_file	*tmp;
	t_file	*new;

	tmp = (*mem);
	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new = malloc(sizeof(t_file) * 1);
	if (!new)
		return (NULL);
	new->fd = fd;
	new->save = NULL;
	new->readed_len = 1;
	new->next = (*mem);
	(*mem) = new;
	return (new);
}

static void	__ft_free__(t_file **mem, int fd)
{
	t_file	*back;
	t_file	*next;
	t_file	*curr;

	back = 0;
	next = (*mem);
	while (next)
	{
		if (next->fd == fd)
		{
			if (back == 0)
				(*mem) = next->next;
			else
				back->next = next->next;
			curr = next;
			next = next->next;
			free(curr);
		}
		else
		{
			back = next;
			next = back->next;
		}
	}
}

char	*__gnl(int fd)
{
	char			*buffer;
	static t_file	*mem;
	t_file			*file;
	char			*line;

	file = __ft_find_file__(&mem, fd);
	if (BUFFER_SIZE < 1 || !file)
		return (NULL);
	buffer = malloc(sizeof(char) * ((long)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_is_line('\n', file->save) && file->readed_len)
	{
		file->readed_len = read(file->fd, buffer, (int)BUFFER_SIZE);
		if (file->readed_len <= 0)
			break ;
		buffer[file->readed_len] = '\0';
		file->save = ft_strjoin(file->save, buffer);
	}
	line = ft_strdup(file->save);
	file->save = ft_get_save(file->save);
	if (file->readed_len == 0 && !file->save)
		__ft_free__(&mem, fd);
	return (free(buffer), line);
}
