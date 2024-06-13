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

#include "../include/checker.h"

void	ft_exec_instruc(char *instruction, t_stack_info *stack_a, \
t_stack_info *stack_b)
{
	if (strcmp(instruction, "sa\n") == 0)
		ft_swap_bonus(stack_a);
	else if (strcmp(instruction, "sb\n") == 0)
		ft_swap_bonus(stack_b);
	else if (strcmp(instruction, "pa\n") == 0)
		ft_push_a_bonus(stack_a, stack_b);
	else if (strcmp(instruction, "pb\n") == 0)
		ft_push_b_bonus(stack_a, stack_b);
	else if (strcmp(instruction, "ra\n") == 0)
		ft_rotate_a_bonus(stack_a);
	else if (strcmp(instruction, "rb\n") == 0)
		ft_rotate_b_bonus(stack_b);
	else if (strcmp(instruction, "rr\n") == 0)
		ft_rotate_both_bonus(stack_a, stack_b);
	else if (strcmp(instruction, "rra\n") == 0)
		ft_reverse_rotate_a_bonus(stack_a);
	else if (strcmp(instruction, "rrb\n") == 0)
		ft_reverse_rotate_b_bonus(stack_b);
	else if (strcmp(instruction, "rrr\n") == 0)
		ft_reverse_rotate_both_bonus(stack_a, stack_b);
}

int	ft_is_sorted_checker(t_ls_db *stack)
{
	t_ls_db	*current;
	t_ls_db	*start;

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

int	main(int argc, char **argv)
{
	t_stack_info	stack_a;
	t_stack_info	stack_b;
	char			*line;

	stack_a.stack = NULL;
	stack_b.stack = NULL;
	if (argc < 2)
		exit(1);
	ft_init_stack_a(&stack_a, argc, argv);
	ft_set_stack(&stack_a, &stack_b);
	ft_update_stack(&stack_a, &stack_b);
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		ft_exec_instruc(line, &stack_a, &stack_b);
		free(line);
	}
	if (ft_is_sorted_checker(stack_a.stack) && stack_b.stack == NULL)
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
	ft_free_memory_a(&stack_a);
	return (0);
}
