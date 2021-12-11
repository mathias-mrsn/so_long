/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:56:09 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/11 18:56:10 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	red_cross(t_data *s)
{
	__printf("Red cross was clicked, good bye see you soon !\n");
	ft_quit("0123", NULL, s);
	return (0);
}

void	__print_end__(char *str, t_data *s)
{
	if (str && __strnstr(str, "Error", INT_MAX))
		__putstr(str, 2);
	else if (str)
	{
		printf("%s\n", str);
		printf("You made %d moves\n", s->map->mouv);
	}
}

int	print_quit(char *str, char *free, int abs, t_data *s)
{
	int	index;
	int	j;

	index = 0;
	__print_end__(str, s);
	while (index < s->map->height)
	{
		j = 0;
		printf("line --> %-5d : \"", index);
		if (abs == index)
			printf("\033[0;31m%s\033[0m", s->map->map[index]);
		else
			printf("\033[0;32m%s\033[0m", s->map->map[index]);
		j++;
		printf("\"\n");
		index++;
	}
	ft_quit(free, NULL, s);
	return (0);
}
