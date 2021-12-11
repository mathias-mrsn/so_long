/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:01:14 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 12:01:15 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*__strtrim(const char *s1, const char *set)
{
	char	*trim;
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	j = __strlen(s1);
	while (s1[i] && __is_charset(s1[i], (char *)set))
		i++;
	while (--j > i && __is_charset(s1[j], (char *)set))
		;
	trim = malloc(sizeof(char) * (j - i + 1));
	if (!trim)
		return (NULL);
	j -= i - 1;
	index = 0;
	while (index < j)
		trim[index++] = s1[i++];
	trim[index] = '\0';
	return (trim);
}
