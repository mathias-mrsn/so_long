/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:50:17 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 11:51:46 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*__memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	if (!src && !dst)
		return (dst);
	if (s1 > s2)
		while (len--)
			s1[len] = s2[len];
	else
	{
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (dst);
}
