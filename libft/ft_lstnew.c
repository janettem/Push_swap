/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:03:41 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/06 12:58:00 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;
	char	*content_cpy;
	size_t	content_size_cpy;

	if (!(link = (t_list *)malloc(sizeof(t_list))))
		return ((t_list *)NULL);
	if (!content)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		content_size_cpy = content_size;
		if (!(content_cpy = (char *)malloc(sizeof(char) * content_size)))
			return ((t_list *)NULL);
		link->content = ft_memcpy(content_cpy, content, content_size);
		link->content_size = content_size_cpy;
	}
	link->next = NULL;
	return (link);
}
