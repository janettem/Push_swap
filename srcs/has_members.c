/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_members.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:55:53 by jmetelin          #+#    #+#             */
/*   Updated: 2020/02/20 14:23:09 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		reverse_rotate_stacks(t_stack *b, t_stack *a, int items[2],
		int places[2])
{
	while (places[0] <= (b->top - 1) / 2 && b->items[b->top - 1] != items[0] &&
			places[1] <= (a->top - 1) / 2 && a->items[0] != items[1])
	{
		reverse_rotate(b);
		reverse_rotate(a);
		ft_printf("rrr\n");
	}
	while (places[0] <= (b->top - 1) / 2 && b->items[b->top - 1] != items[0])
	{
		reverse_rotate(b);
		ft_printf("rrb\n");
	}
	while (places[1] <= (a->top - 1) / 2 && a->items[0] != items[1])
	{
		reverse_rotate(a);
		ft_printf("rra\n");
	}
}

void		rotate_stacks(t_stack *b, t_stack *a, int items[2], int places[2])
{
	while (places[0] > (b->top - 1) / 2 && b->items[b->top - 1] != items[0] &&
			places[1] > (a->top - 1) / 2 && a->items[0] != items[1])
	{
		rotate(b);
		rotate(a);
		ft_printf("rr\n");
	}
	while (places[0] > (b->top - 1) / 2 && b->items[b->top - 1] != items[0])
	{
		rotate(b);
		ft_printf("rb\n");
	}
	while (places[1] > (a->top - 1) / 2 && a->items[0] != items[1])
	{
		rotate(a);
		ft_printf("ra\n");
	}
}

static int	get_mvs(t_stack *b, t_stack *a, int limits[2], int member)
{
	int		mvs;
	int		mvs_a;
	int		place;

	mvs = member > (b->top - 1) / 2 ? b->top - member : member + 2;
	place = a->top - 1;
	while (b->items[member] > limits[0] && b->items[member] < limits[1] &&
			place > 0 && (b->items[member] < a->items[place] ||
				b->items[member] > a->items[place - 1]))
		place--;
	while ((b->items[member] < limits[0] || b->items[member] > limits[1]) &&
			place >= 0 && a->items[place] != limits[1])
		place--;
	mvs_a = place > (a->top - 1) / 2 ? a->top - place : place;
	if ((member > (b->top - 1) / 2 && place > (a->top - 1) / 2) ||
			(member <= (b->top - 1) / 2 && place <= (a->top - 1) / 2))
		mvs = mvs > mvs_a ? mvs : mvs_a;
	else
		mvs += mvs_a;
	return (mvs);
}

int			get_member_to_push_and_sort(t_stack *b, t_stack *a, int *group)
{
	int		member;
	int		mvs;
	int		cmp;
	int		limits[2];
	int		i;

	limits[0] = get_smallest(a);
	limits[1] = get_biggest(a);
	i = b->top - 1;
	while (i >= 0 && (b->items[i] < group[0] || b->items[i] > group[1]))
		i--;
	member = i;
	mvs = get_mvs(b, a, limits, member);
	while (--i >= 0)
	{
		if (b->items[i] >= group[0] && b->items[i] <= group[1] &&
				(mvs > (cmp = get_mvs(b, a, limits, i)) ||
				(mvs == cmp && b->items[member] < b->items[i])))
		{
			member = i;
			mvs = cmp;
		}
	}
	return (member);
}

int			has_members(t_stack *stack, int *group)
{
	int		i;

	i = stack->top;
	while (--i >= 0)
	{
		if (stack->items[i] >= group[0] && stack->items[i] <= group[1])
			return (1);
	}
	return (0);
}
