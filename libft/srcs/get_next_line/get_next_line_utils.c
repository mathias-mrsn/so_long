#include "../../includes/get_next_line.h"

int		ft_strlen_bis(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_bis(char *src)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen_bis(src) + 1);
	if (!res)
		return (NULL);
	while (src[i] && src[i] != '\n')
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_bis(char *s1, char *s2)
{
	size_t 	i;
	size_t 	j;
	char	*newstr;

	if(!s1 || !s2)
		return (NULL);
	i = ft_strlen_bis(s1);
	j = ft_strlen_bis(s2);
	newstr = malloc(sizeof(char) * (i + j + 1));
	if(!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while(s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	free(s1);
	return (newstr);
}

int	ft_is_line(char c, char *set)
{
	if(!set)
		return (0);
	while(*set)
	{
		if(c == *set)
			return (1);
		set++;
	}
	return (0);
}

char *ft_get_save(char *src)
{
	char	*res;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	while(src[i] && src[i] != '\n')
		i++;
	if(src[i])
		i++;
	res = (char *)malloc(sizeof(char) * (ft_strlen_bis(src + i) + 1));
	if (!res)
		return (NULL);
	while (src[i])
	{
		res[j] = src[i];
		i++;
		j++;
	}
	res[j] = '\0';
	free(src);
	return (res);
}