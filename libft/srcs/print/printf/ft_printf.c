/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:36:29 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 13:55:52 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	__printf(const char *str, ...)
{
	va_list		settings;
	t_options	options;
	t_argument	arg;

	va_start(settings, str);
	options.printed_length = 0;
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			ft_parse_hub(&options, &str, settings, &arg);
			ft_print_hub(&options, &arg);
		}
		else
			ft_putchar(*str++, 1, &options);
	}
	va_end(settings);
	return (options.printed_length);
}
