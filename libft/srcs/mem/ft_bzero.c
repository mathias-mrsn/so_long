/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:47:55 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 11:47:56 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	__bzero(void *b, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len--)
		str[len] = 0;
}
