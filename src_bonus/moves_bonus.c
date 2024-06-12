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

#include "../include/checker.h"

void	ft_swap_bonus(t_stack_info *info)
{
	t_ls_db	*first;
	t_ls_db	*second;

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
}

void	ft_rotate_a_bonus(t_stack_info *info)
{
	t_ls_db	*new_head;

	if (info == NULL || info->stack == NULL || info->stack->next == NULL)
		return ;
	new_head = info->stack->next;
	info->stack = new_head;
}

t_ls_db	*ft_rotate_b_bonus(t_stack_info *info)
{
	t_ls_db	*first;

	if (info == NULL || info->stack == NULL || info->stack->next == NULL)
		return (NULL);
	first = info->stack;
	info->stack = first->next;
	return (info->stack);
}

t_ls_db	*ft_reverse_rotate_a_bonus(t_stack_info *info)
{
	t_ls_db	*first;

	if (info == NULL || info->stack == NULL || info->stack->next == NULL)
		return (NULL);
	first = info->stack;
	info->stack = first->prev;
	return (info->stack);
}

t_ls_db	*ft_reverse_rotate_b_bonus(t_stack_info *info)
{
	t_ls_db	*first;

	if (info == NULL || info->stack == NULL || info->stack->next == NULL)
		return (NULL);
	first = info->stack;
	info->stack = first->prev;
	return (info->stack);
}
