/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:52:58 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 11:52:59 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	__lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = (*alst);
	if (!tmp)
		(*alst) = new;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			return ;
		}
		tmp = tmp->next;
	}
}
