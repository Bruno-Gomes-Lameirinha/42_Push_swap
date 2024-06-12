/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:11:49 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/06/10 19:11:51 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print_list(t_stack_info *info)
{
	p_list	*current;

	if (info->stack == NULL)
		return;
	current = info->stack;
	while (current->next != info->stack)
	{
		ft_printf("content %d  pos: %d  index: %d cost: %d  target: %d\n", *current->content, current->position, current->index, current->cost, current->target_index);
		current = current->next;
	}
	ft_printf("content %d  pos: %d  index: %d cost: %d target: %d\n", *current->content, current->position, current->index, current->cost, current->target_index);
}

	//ft_printf("stack a\n");
	//ft_print_list(&stack_a);
	//ft_printf("stack b\n");
	//ft_print_list(&stack_b);