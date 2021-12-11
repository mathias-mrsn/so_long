/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:00:06 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 12:00:07 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	__strlcat(char *dest, const char *src, size_t size)
{
	size_t	l;
	size_t	i;

	l = 0;
	while (dest[l] && l < size)
		l++;
	i = 0;
	while (src[i] && size && l + i < size - 1)
	{
		dest[l + i] = src[i];
		i++;
	}
	if (l < size)
		dest[l + i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (l + i);
}
