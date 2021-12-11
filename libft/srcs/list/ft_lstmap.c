/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:53:56 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 11:55:16 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*__lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newelem;

	new = 0;
	if (!f || !del || !lst)
		return (NULL);
	while (lst)
	{
		newelem = __lstnew((*f)(lst->content));
		if (!newelem)
		{
			__lstclear(&new, del);
			return (new);
		}
		__lstadd_back(&new, newelem);
		lst = lst->next;
	}
	return (new);
}
