/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:16:54 by jmetelin          #+#    #+#             */
/*   Updated: 2020/02/20 14:17:07 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "checker.h"

void	sort_b(t_stack *b);
void	put_smallest_to_top(t_stack *a, t_stack *b);
void	sort_many_nbrs(t_stack *a, t_stack *b);
int		**get_groups(t_stack *stack, int amount);
void	push_group(t_stack *a, t_stack *b, int *group);
void	push_and_sort_group(t_stack *b, t_stack *a, int *group);
int		has_members(t_stack *stack, int *group);
int		get_member_to_push_and_sort(t_stack *b, t_stack *a, int *group);
void	rotate_stacks(t_stack *b, t_stack *a, int items[2], int places[2]);
void	reverse_rotate_stacks(t_stack *b, t_stack *a, int items[2],
		int places[2]);
void	sort_a(t_stack *a);
int		get_smallest(t_stack *stack);
int		get_biggest(t_stack *stack);

#endif
