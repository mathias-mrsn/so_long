/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:58:49 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 11:58:50 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*__strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		if (s[i] == 0)
			return (NULL);
		i++;
	}
	return (NULL);
}
