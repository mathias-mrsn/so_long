#include "../../includes/so_long.h"

long __random(int len_max)
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

int max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}