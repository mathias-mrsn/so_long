#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//----------------------------------------------------------------

# define BUFFER_SIZE 10000000
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

// Leaks OK !
// Norme No
// Do more test !

//----------------------------------------------------------------

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct		s_file
{
	int				fd;
	char			*save;
	struct s_file	*next;
}					t_file;

char *ft_get_save(char *str);
int	ft_is_line(char c, char *set);
char	*ft_strjoin_bis(char *s1, char *s2);
char	*ft_strdup_bis(char *src);
int		ft_strlen_bis(char *str);
char *get_next_line(int fd);

#endif
