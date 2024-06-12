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

	if (stack == NULL || stack->next == stack) {
		return 1;
	}
	start = stack;
	current = stack;
	while (current->next != start) {
		if (*current->content > *current->next->content) {
			return 0;
		}
		current = current->next;
	}
	return 1;
}

void	ft_tiny_sort(t_stack_info *info)
{
	if (ft_is_sorted(info->stack))
		return;
	if (info->max == *info->stack->content)
		ft_rotate_a(info);
	if (*info->stack->content < *info->stack->next->content && info->max == *info->stack->next->content)
		{
			ft_swap(info);
			ft_rotate_a(info);
		}
	if (*info->stack->content > *info->stack->next->content)
		ft_swap(info);
}

void	ft_update_stack(t_stack_info *info_a, t_stack_info *info_b)
{
	ft_update_min_max(info_a);
	ft_update_pos(&(info_a->stack));
	info_a->len = ft_lstsize_db(info_a);
	ft_update_min_max(info_b);
	ft_update_pos(&(info_b->stack));
	info_b->len = ft_lstsize_db(info_b);
}

void	ft_make_moves(t_stack_info *info_a, t_stack_info *info_b)
{
	p_list *node_min_cost;
	int moves_a;
	int moves_b;
	
	node_min_cost = ft_find_min_cost_node(info_b);
	moves_a = ft_calculate_moves_a(info_a, node_min_cost->target_pos);
	moves_b = ft_calculate_moves_b(info_b, node_min_cost->position);

	ft_execute_combined_moves(info_a, info_b, &moves_a, &moves_b);
	ft_finalize_moves_a(info_a, node_min_cost, moves_a);
	ft_finalize_moves_b(info_b, node_min_cost, moves_b);
	ft_push_a(info_a, info_b);
}
void	ft_init_stack_a(t_stack_info *info_a, int argc, char **argv)
{
	char **args;
	int	i;
	p_list *new;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	while (args[i]) 
	{
		new = ft_lstnew_dbl(ft_atoi(args[i]));
		info_a->stack = ft_lstadd_back_dbl(&(info_a->stack), new);
		i++;
	}
	if (argc == 2)
		free(args);

}

int	main(int argc, char **argv)
{
	t_stack_info stack_a;
	t_stack_info stack_b;

	stack_a.stack = NULL;
	stack_b.stack = NULL;
	if (argc < 2)
		exit(1);
	ft_init_stack_a(&stack_a, argc, argv);
	if(!ft_is_sorted(stack_a.stack))
	{
		ft_set_stack(&stack_a, &stack_b);
		ft_update_stack(&stack_a,  &stack_b);
		while (stack_a.len > 3)
		{
			if(stack_a.max == *stack_a.stack->content)
				ft_rotate_a(&stack_a);
			ft_push_b(&stack_a, &stack_b);
			ft_update_stack(&stack_a, &stack_b);
		}
		ft_tiny_sort(&stack_a);
	}
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
		ft_printf("stack a\n");
		ft_print_list(&stack_a);
		ft_printf("stack b\n");
		ft_print_list(&stack_b);
	return 0;
}
