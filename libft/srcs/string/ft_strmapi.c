/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:00:32 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 12:00:33 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*__strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	newstr = malloc(sizeof(char) * __strlen(s) + 1);
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
