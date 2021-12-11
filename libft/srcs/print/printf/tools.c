/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:36:38 by mamaurai          #+#    #+#             */
/*   Updated: 2021/11/29 10:39:40 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_charset(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int	ft_nbrlen_b_u(unsigned long n, char *base)
{
	int	i;
	int	base_len;

	base_len = ft_strlen(base);
	i = 1;
	if (base_len <= 1)
		return (0);
	while (n >= (unsigned long)base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

int	ft_nbrlen_b(long long n, char *base)
{
	int			i;
	long long	base_len;

	base_len = ft_strlen(base);
	i = 1;
	if (base_len <= 1)
		return (0);
	while (n >= base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

void	ft_putchar(char c, int fd, t_options *options)
{
	write(fd, &c, 1);
	options->printed_length++;
}
