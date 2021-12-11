/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:44:51 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 11:46:59 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	__putnbr(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (n < 0)
		__putchar('-', fd);
	if (nb > 9)
		__putnbr(nb / 10, fd);
	__putchar(nb % 10 + 48, fd);
}
