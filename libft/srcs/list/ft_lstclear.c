/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:53:12 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 11:53:13 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	__lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*tmp;

	curr = (*lst);
	while (curr)
	{
		del(curr->content);
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	(*lst) = NULL;
}
