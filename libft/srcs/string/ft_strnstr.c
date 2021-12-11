/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:00:53 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 12:00:54 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*__strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[0])
		return ((char *)(haystack));
	while (i < len && haystack[i])
	{
		j = 0;
		while (i + j < len && needle[j] == haystack[i + j])
		{
			if (!needle[j + 1])
				return ((char *)haystack + i);
			j++;
		}
		++i;
	}
	return (0);
}
