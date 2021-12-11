/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:48:17 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/04 17:33:24 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	__ft_strlen__(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!src)
		return (NULL);
	res = (char *)malloc(sizeof(char) * __ft_strlen__(src) + 1);
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	if (!s1)
		s1 = ft_strdup("\0");
	if (!s2)
		return (NULL);
	newstr = malloc(sizeof(char) * (__ft_strlen__(s1) + __ft_strlen__(s2) + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		newstr[i] = s1[i];
	while (s2[++j])
		newstr[i + j] = s2[j];
	newstr[i + j] = '\0';
	return (free(s1), newstr);
}

int	ft_is_line(char c, char *set)
{
	while (set && *set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_get_save(char *src)
{
	char		*res;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!src)
		return (NULL);
	while (src[i] && src[i] != '\n')
		i++;
	if (!src[i] || !src[i + 1])
		return (free(src), NULL);
	if (src[i])
		i++;
	res = (char *)malloc(sizeof(char) * (__ft_strlen__(src + i) + 1));
	if (!res)
		return (NULL);
	while (src[i])
	{
		res[j] = src[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (free(src), res);
}
