/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:44:29 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 11:44:30 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	__putaddr(void *addr, int fd)
{
	size_t	address;
	size_t	div;

	div = 16;
	address = (size_t)addr;
	write(fd, "0x", 2);
	while (address / div > 15)
		div *= 16;
	while (div > 0)
	{
		write(fd, &HEXA_LOWER[address / div], 1);
		address %= div;
		div /= 16;
	}
}
