/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:44:58 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 11:46:42 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	__putnstr(char *str, int fd, size_t len)
{
	if (!str)
		return ;
	while (*str && len--)
		__putchar(*str++, fd);
}
