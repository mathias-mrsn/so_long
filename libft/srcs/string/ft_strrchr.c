/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:01:01 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 12:01:02 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*__strrchr(const char *s, int c)
{
	size_t	i;

	i = __strlen(s) + 1;
	while (i--)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	return (NULL);
}
