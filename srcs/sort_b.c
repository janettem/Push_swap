/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:47:27 by jmetelin          #+#    #+#             */
/*   Updated: 2020/02/20 14:41:54 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_many_nbrs(t_stack *a, t_stack *b)
{
	int		**groups;
	int		amount;
	int		i;

	if (a->top < 75)
		amount = 1;
	else if (a->top < 100)
		amount = 2;
	else
		amount = 3;
	groups = get_groups(a, amount);
	i = 1;
	while (i <= groups[0][0])
		push_group(a, b, groups[i++]);
	i = groups[0][0];
	while (i > 0)
	{
		push_and_sort_group(b, a, groups[i]);
		free(groups[i--]);
	}
	free(groups[i]);
	free(groups);
	sort_a(a);
}

static void	rotate_stack(t_stack *b, int item, int place)
{
	while (place > (b->top - 1) / 2 && b->items[0] != item)
	{
		rotate(b);
		ft_printf("rb\n");
	}
	while (place <= (b->top - 1) / 2 && b->items[0] != item)
	{
		reverse_rotate(b);
		ft_printf("rrb\n");
	}
}

static void	push_and_sort(t_stack *a, t_stack *b)
{
	int		place;
	int		smallest;
	int		biggest;

	if (b->top > 1)
	{
		smallest = get_smallest(b);
		biggest = get_biggest(b);
		place = b->top - 1;
		while (a->items[a->top - 1] > smallest && a->items[a->top - 1] < biggest
				&& place > 0 && (a->items[a->top - 1] > b->items[place] ||
					a->items[a->top - 1] < b->items[place - 1]))
			place--;
		while ((a->items[a->top - 1] < smallest ||
					a->items[a->top - 1] > biggest) && place >= 0 &&
				b->items[place] != smallest)
			place--;
		rotate_stack(b, b->items[place], place);
	}
	push_inst(b, a);
	ft_printf("pb\n");
}

void		put_smallest_to_top(t_stack *a, t_stack *b)
{
	if (a->items[a->top - 1] < a->items[a->top - 2] &&
			a->items[a->top - 1] < a->items[0])
		push_and_sort(a, b);
	else if (a->items[a->top - 2] < a->items[a->top - 1] &&
			a->items[a->top - 2] <= a->items[0])
	{
		swap(a);
		ft_printf("sa\n");
	}
	else if (a->items[0] < a->items[a->top - 1] &&
			a->items[0] < a->items[a->top - 2])
	{
		reverse_rotate(a);
		ft_printf("rra\n");
	}
}

void		sort_b(t_stack *b)
{
	int		place;
	int		biggest;

	if (b->top > 1)
	{
		biggest = get_biggest(b);
		place = b->top - 1;
		while (place >= 0 && b->items[place] != biggest)
			place--;
		while (place > (b->top - 1) / 2 && b->items[b->top - 1] != biggest)
		{
			rotate(b);
			ft_printf("rb\n");
		}
		while (place <= (b->top - 1) / 2 && b->items[b->top - 1] != biggest)
		{
			reverse_rotate(b);
			ft_printf("rrb\n");
		}
	}
}
