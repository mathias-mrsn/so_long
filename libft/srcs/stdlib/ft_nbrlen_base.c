/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:56:47 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 11:57:07 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	__nbrlen_base(int64_t nbr, char *base)
{
	const uint32_t	base_len = __strlen(base);
	int				len;

	len = 1;
	if (nbr < 0 && len++)
		nbr *= -1;
	while (nbr / base_len)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}
