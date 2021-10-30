#include "../../includes/get_next_line.h"

t_file	*ft_find_file(t_file **mem, int fd)
{
	t_file	*tmp;
	t_file	*new;

	tmp = (*mem);
	while(tmp)
	{
		if(tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new = malloc(sizeof(t_file));
	if(!new)
		return (NULL);
	new->fd = fd;
	new->save = NULL;
	new->next = (*mem);
	(*mem) = new;
	return (new);
}

void	ft_free(t_file **mem, int fd)
{
	t_file *back;
	t_file *next;
	t_file *curr;

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
			free(curr->save);
			free(curr);
		}
		else
		{
			back = next;
			next = back->next;
		}
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static t_file	*mem;
	t_file		*file;
	int			len;
	char		*line;

	file = ft_find_file(&mem, fd);
	if (BUFFER_SIZE < 1 || fd < 0 || !file)
		return (NULL);
	buffer = malloc(sizeof(char) * (int)(BUFFER_SIZE + 1));
	if(!buffer)
		return(free(buffer), NULL);
	if(!file->save)
		file->save = ft_strdup_bis("\0");
	len = 1;
	while(!ft_is_line('\n', file->save) && len)
	{
		len = read(file->fd, buffer, (int)BUFFER_SIZE);
		if(len < 0)
			return (free(buffer), NULL);
		buffer[len] = '\0';
		file->save = ft_strjoin_bis(file->save, buffer);
	}
	line = ft_strdup_bis(file->save);
	file->save = ft_get_save(file->save);
	free(buffer);
	if(len <= 0 && !file->save[0] && !line[0])
	 	return (ft_free(&mem, fd), free(line), NULL);
	return (line);
}



/*

int main(int argc, char **argv)
{
	if (argc)
	{
		char *res;
		char *res2;
		char *res3;
		int i = 50;
		int fd = open(argv[1], O_RDONLY);
		int	fd2 = open(argv[2], O_RDONLY);
		int	fd3 = open(argv[3], O_RDONLY);
		while(i--)
		{
			res = get_next_line(fd);
			if(res)
				printf("%s", res);
			res2 = get_next_line(fd2);
			if(res2)
				printf("%s", res2);
			res3 = get_next_line(fd3);
			if(res3)
				printf("%s", res3);
			free(res);
			free(res2);
			free(res3);

		}
	}
	return (0);
}

*/