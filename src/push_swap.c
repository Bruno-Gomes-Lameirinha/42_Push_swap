/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:34:16 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/06/10 20:17:39 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_sorted(p_list *stack)
{
	p_list	*current;
	p_list	*start;

	if (stack == NULL || stack->next == stack)
		return (1);
	start = stack;
	current = stack;
	while (current->next != start)
	{
		if (*current->content > *current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_tiny_sort(t_stack_info *info)
{
	if (ft_is_sorted(info->stack))
		return ;
	if (info->total_len == 3 && *info->stack->next->next->content == \
	info->min && *info->stack->content != info->max)
		ft_reverse_rotate_a(info);
	if (info->max == *info->stack->content)
		ft_rotate_a(info);
	if (*info->stack->content < *info->stack->next->content && \
	info->max == *info->stack->next->content && info->total_len > 2)
	{
		ft_swap(info);
		ft_rotate_a(info);
	}
	if (*info->stack->content > *info->stack->next->content)
		ft_swap(info);
}

void	ft_make_moves(t_stack_info *info_a, t_stack_info *info_b)
{
	p_list	*node_min_cost;
	int		moves_a;
	int		moves_b;

	node_min_cost = ft_find_min_cost_node(info_b);
	moves_a = ft_calculate_moves_a(info_a, node_min_cost->target_pos);
	moves_b = ft_calculate_moves_b(info_b, node_min_cost->position);
	ft_execute_combined_moves(info_a, info_b, &moves_a, &moves_b);
	ft_finalize_moves_a(info_a, node_min_cost, moves_a);
	ft_finalize_moves_b(info_b, node_min_cost, moves_b);
	ft_push_a(info_a, info_b);
}

void	ft_send_nodes_to_stack_b(t_stack_info *stack_a, t_stack_info *stack_b)
{
	if (!ft_is_sorted(stack_a->stack))
	{
		ft_set_stack(stack_a, stack_b);
		ft_update_stack(stack_a, stack_b);
		while (stack_a->len > 3)
		{
			if (stack_a->max == *stack_a->stack->content)
				ft_rotate_a(stack_a);
			ft_push_b(stack_a, stack_b);
			ft_update_stack(stack_a, stack_b);
		}
		ft_tiny_sort(stack_a);
	}
	else
		exit(1);
}

int	main(int argc, char **argv)
{
	t_stack_info	stack_a;
	t_stack_info	stack_b;

	stack_a.stack = NULL;
	stack_b.stack = NULL;
	if (argc < 2)
		exit(1);
	ft_init_stack_a(&stack_a, argc, argv);
	ft_send_nodes_to_stack_b(&stack_a, &stack_b);
	while (stack_b.stack != NULL)
	{
		ft_update_stack(&stack_a, &stack_b);
		ft_get_cost(&stack_a, &stack_b);
		ft_make_moves(&stack_a, &stack_b);
	}
	if (stack_a.stack->index != 1)
	{
		ft_update_stack(&stack_a, &stack_b);
		ft_finish_stack(&stack_a);
	}
	return (0);
}
