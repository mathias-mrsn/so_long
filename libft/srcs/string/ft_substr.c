/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:01:24 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 12:02:40 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*__substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	if (__strlen(s) <= start)
		len = 0;
	if (__strlen(s) <= len)
		len = __strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (s[i + start] && i < len)
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}
