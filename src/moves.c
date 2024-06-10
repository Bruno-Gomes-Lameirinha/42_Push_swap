/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:26:13 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/06/10 17:33:53 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_stack_info *info)
{
	p_list	*first;
	p_list	*second;

	if (info == NULL || info->stack == NULL || info->stack->next == NULL)
		return ;
	first = info->stack;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev->next = second;
	first->prev = second;
	info->stack = second;
	if (info->letter == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	ft_rotate_a(t_stack_info *info)
{
	p_list	*new_head;

	if (info == NULL || info->stack == NULL || info->stack->next == NULL)
		return ;
	new_head = info->stack->next;
	info->stack = new_head;
	ft_printf("ra\n");
}

p_list	*ft_rotate_b(t_stack_info *info)
{
	p_list	*first;

	if (info == NULL || info->stack == NULL || info->stack->next == NULL)
		return (NULL);
	first = info->stack;
	info->stack = first->next;
	ft_printf("rb\n");
	return (info->stack);
}

p_list	*ft_reverse_rotate_a(t_stack_info *info)
{
	p_list	*first;

	if (info == NULL || info->stack == NULL || info->stack->next == NULL)
		return (NULL);
	first = info->stack;
	info->stack = first->prev;
	ft_printf("rra\n");
	return (info->stack);
}

p_list	*ft_reverse_rotate_b(t_stack_info *info)
{
	p_list	*first;

	if (info == NULL || info->stack == NULL || info->stack->next == NULL)
		return (NULL);
	first = info->stack;
	info->stack = first->prev;
	ft_printf("rrb\n");
	return (info->stack);
}
