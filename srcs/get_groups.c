/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_groups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:51:42 by jmetelin          #+#    #+#             */
/*   Updated: 2020/02/20 14:22:40 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_and_sort_group(t_stack *b, t_stack *a, int *group)
{
	int		items[2];
	int		places[2];
	int		smallest;
	int		biggest;

	while (has_members(b, group))
	{
		smallest = get_smallest(a);
		biggest = get_biggest(a);
		places[0] = get_member_to_push_and_sort(b, a, group);
		items[0] = b->items[places[0]];
		places[1] = a->top - 1;
		while (items[0] > smallest && items[0] < biggest && places[1] > 0 &&
				(items[0] < a->items[places[1]] ||
				items[0] > a->items[places[1] - 1]))
			places[1]--;
		while ((items[0] < smallest || items[0] > biggest) && places[1] >= 0 &&
				a->items[places[1]] != biggest)
			places[1]--;
		items[1] = a->items[places[1]];
		rotate_stacks(b, a, items, places);
		reverse_rotate_stacks(b, a, items, places);
		push_inst(a, b);
		ft_printf("pa\n");
	}
}

static int	get_member_to_push(t_stack *stack, int *group)
{
	int		member;
	int		mvs;
	int		cmp;
	int		i;

	i = stack->top - 1;
	while (i >= 0 && (stack->items[i] < group[0] || stack->items[i] > group[1]))
		i--;
	member = i;
	mvs = member > (stack->top - 1) / 2 ? stack->top - member : member + 2;
	while (--i >= 0)
	{
		if (stack->items[i] >= group[0] && stack->items[i] <= group[1])
		{
			cmp = i > (stack->top - 1) / 2 ? stack->top - i : i + 2;
			if (mvs > cmp ||
					(mvs == cmp && stack->items[member] > stack->items[i]))
			{
				member = i;
				mvs = cmp;
			}
		}
	}
	return (member);
}

void		push_group(t_stack *a, t_stack *b, int *group)
{
	int		member;
	int		place;

	while (a->top > 2 && has_members(a, group))
	{
		place = get_member_to_push(a, group);
		member = a->items[place];
		while (place > (a->top - 1) / 2 && a->items[a->top - 1] != member)
		{
			rotate(a);
			ft_printf("ra\n");
		}
		while (place <= (a->top - 1) / 2 && a->items[a->top - 1] != member)
		{
			reverse_rotate(a);
			ft_printf("rra\n");
		}
		push_inst(b, a);
		ft_printf("pb\n");
	}
}

static void	fill_groups(int **groups, int amount, int smallest, int biggest)
{
	int		i;

	i = 1;
	if (i <= amount)
	{
		groups[i][0] = smallest;
		groups[i][1] = groups[i][0] + ((biggest - smallest) / amount);
	}
	while (++i < amount)
	{
		groups[i][0] = groups[i - 1][1] + 1;
		groups[i][1] = groups[i][0] + ((biggest - smallest) / amount);
	}
	if (i == amount)
	{
		groups[i][0] = groups[i - 1][1] + 1;
		groups[i][1] = biggest;
	}
}

int			**get_groups(t_stack *stack, int amount)
{
	int		**groups;
	int		smallest;
	int		biggest;
	int		i;

	smallest = get_smallest(stack);
	biggest = get_biggest(stack);
	if (!(groups = (int **)malloc(sizeof(int *) * (amount + 1))))
		handle_error();
	i = 0;
	if (!(groups[i] = (int *)malloc(sizeof(int))))
		handle_error();
	groups[i][0] = amount;
	while (++i <= amount)
	{
		if (!(groups[i] = (int *)malloc(sizeof(int) * 2)))
			handle_error();
	}
	fill_groups(groups, amount, smallest, biggest);
	return (groups);
}
