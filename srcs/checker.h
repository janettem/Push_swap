/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:13:55 by jmetelin          #+#    #+#             */
/*   Updated: 2020/02/20 12:45:43 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct	s_stack
{
	int		max_size;
	int		top;
	int		*items;
}				t_stack;

char			**get_nbrs(char **av, int ac);
t_stack			*initialize(int size);
void			fill(t_stack *stack, char **ints);
void			swap(t_stack *stack);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);
void			push_inst(t_stack *dst, t_stack *src);
void			push(t_stack *stack, int item);
int				pop(t_stack *stack);
int				is_sorted(t_stack *a, t_stack *b);
void			handle_error(void);

#endif
