/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:10:24 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/06 10:31:59 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current_link;
	t_list	*next_link;

	if (alst && *alst)
	{
		current_link = *alst;
		while (current_link)
		{
			del(current_link->content, current_link->content_size);
			next_link = current_link->next;
			free(current_link);
			current_link = next_link;
		}
		*alst = NULL;
	}
}
