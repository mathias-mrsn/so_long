/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:59:29 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 12:02:00 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	__striteri(char *s, void (*f)(unsigned int, char*))
{
	uint32_t	index;

	if (!s)
		return ;
	index = -1;
	while (s[++index])
		(*f)(index, &s[index]);
}
