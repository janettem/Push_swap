/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:45:19 by jmetelin          #+#    #+#             */
/*   Updated: 2020/02/20 13:46:16 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	handle_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int		is_sorted(t_stack *a, t_stack *b)
{
	int		item;
	int		i;

	i = a->top - 1;
	if (i > 0)
	{
		item = a->items[i--];
		while (i >= 0)
		{
			if (item > a->items[i])
				return (0);
			item = a->items[i--];
		}
	}
	if (b->top > 0)
		return (0);
	return (1);
}

int		pop(t_stack *stack)
{
	int		item;

	if (stack->top == 0)
		handle_error();
	stack->top--;
	item = stack->items[stack->top];
	return (item);
}
