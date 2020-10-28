# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 13:55:32 by jmetelin          #+#    #+#              #
#    Updated: 2020/02/20 14:20:01 by jmetelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = project

SRCS = srcs/get_nbrs.c srcs/swap.c srcs/pop.c


all: $(NAME)

checker:
	make -C libft
	gcc srcs/checker.c $(SRCS) -L. libft/libft.a -o checker

push_swap:
	make -C libft
	gcc srcs/push_swap.c srcs/sort_b.c srcs/get_groups.c srcs/has_members.c \
		srcs/sort_a.c $(SRCS) -L. libft/libft.a -o push_swap

$(NAME): checker push_swap

clean:
	/bin/rm -f *.o
	make clean -C libft

fclean: clean
	/bin/rm -f checker push_swap
	make fclean -C libft

re: fclean all
