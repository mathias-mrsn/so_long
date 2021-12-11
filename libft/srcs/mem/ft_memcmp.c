/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:50:06 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 11:50:07 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	__memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	i = 0;
	while (i < n && s[i] == d[i])
		i++;
	if (i == n)
		return (0);
	return (s[i] - d[i]);
}
