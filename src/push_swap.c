/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:34:16 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/05/07 20:19:25 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_is_sorted(p_list *stack) 
{
	p_list *current;
	p_list *start;

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

void    ft_tiny_sort(t_stack_info *info)
{
	if (ft_is_sorted(info->stack))
		return;
	if(info->max == *info->stack->content)
		ft_rotate_a(info);
	if(*info->stack->content < *info->stack->next->content && info->max == *info->stack->next->content)
		{
			ft_swap(info);
			ft_rotate_a(info);
		}
	if(*info->stack->content > *info->stack->next->content)
		ft_swap(info);
}

void    ft_update_stack(t_stack_info *info_a, t_stack_info *info_b)
{
	ft_update_min_max(info_a);
	ft_update_pos(&(info_a->stack));
	info_a->len = ft_lstsize_db(info_a);
	ft_update_min_max(info_b);
	ft_update_pos(&(info_b->stack));
	info_b->len = ft_lstsize_db(info_b);
}

int main(int argc, char **argv) 
{
	t_stack_info stack_a;
	t_stack_info stack_b;
	p_list *new;
	int i;
	char **args;

	i = 0;
	stack_a.stack = NULL;
	stack_b.stack = NULL;
	if (argc < 2)
		exit(1);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	
	while (args[i]) {
		new = ft_lstnew_dbl(ft_atoi(args[i]));
		stack_a.stack = ft_lstadd_back_dbl(&(stack_a.stack), new);
		i++;
	}
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
		ft_make_moves_test(&stack_a, &stack_b);
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

	if (argc == 2)
		free(args);

	return 0;
}
