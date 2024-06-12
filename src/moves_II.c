/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:31:29 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/06/10 17:34:49 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_b(t_stack_info *info_a, t_stack_info *info_b)
{
	t_ls_db	*node_to_push;

	if (info_a == NULL || info_a->stack == NULL)
		return ;
	node_to_push = info_a->stack;
	if (node_to_push->next == node_to_push)
		info_a->stack = NULL;
	else
	{
		info_a->stack = node_to_push->next;
		node_to_push->next->prev = node_to_push->prev;
		node_to_push->prev->next = info_a->stack;
	}
	node_to_push->next = NULL;
	node_to_push->prev = NULL;
	ft_lstadd_front_db(info_b, node_to_push);
	ft_printf("pb\n");
}

void	ft_push_a(t_stack_info *info_a, t_stack_info *info_b)
{
	t_ls_db	*node_to_push;

	if (info_b == NULL || info_b->stack == NULL)
		return ;
	node_to_push = info_b->stack;
	if (node_to_push->next == node_to_push)
	{
		info_b->stack = NULL;
	}
	else
	{
		info_b->stack = node_to_push->next;
		node_to_push->next->prev = node_to_push->prev;
		node_to_push->prev->next = info_b->stack;
	}
	node_to_push->next = NULL;
	node_to_push->prev = NULL;
	ft_lstadd_front_db(info_a, node_to_push);
	ft_printf("pa\n");
}

void	ft_rotate_both(t_stack_info *stack_a, t_stack_info *stack_b)
{
	t_ls_db	*first_a;
	t_ls_db	*first_b;

	if (stack_a == NULL || stack_a->stack == NULL || \
	stack_a->stack->next == NULL)
		return ;
	if (stack_b == NULL || stack_b->stack == NULL || \
	stack_b->stack->next == NULL)
		return ;
	first_a = stack_a->stack;
	stack_a->stack = first_a->next;
	first_b = stack_b->stack;
	stack_b->stack = first_b->next;
	ft_printf("rr\n");
}

void	ft_reverse_rotate_both(t_stack_info *stack_a, t_stack_info *stack_b)
{
	t_ls_db	*first_a;
	t_ls_db	*first_b;

	if (stack_a == NULL || stack_a->stack == NULL || \
	stack_a->stack->next == NULL)
		return ;
	if (stack_b == NULL || stack_b->stack == NULL || \
	stack_b->stack->next == NULL)
		return ;
	first_a = stack_a->stack;
	stack_a->stack = first_a->prev;
	first_b = stack_b->stack;
	stack_b->stack = first_b->prev;
	ft_printf("rrr\n");
}
