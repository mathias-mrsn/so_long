/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:41:54 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 11:41:55 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	__isalnum(int c)
{
	if (__isdigit(c) || __isdigit(c))
		return (1);
	return (0);
}
