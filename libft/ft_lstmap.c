/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:47:05 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/06 12:34:30 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*current_link;

	if (lst)
	{
		if (!(new_lst = f(lst)))
			return ((t_list *)NULL);
		lst = lst->next;
		current_link = new_lst;
		while (lst)
		{
			if (!(current_link->next = f(lst)))
				return ((t_list *)NULL);
			lst = lst->next;
			current_link = current_link->next;
		}
		current_link->next = NULL;
		return (new_lst);
	}
	return ((t_list *)NULL);
}
