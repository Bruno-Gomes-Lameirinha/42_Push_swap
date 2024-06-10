/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:05:03 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/06/10 19:10:59 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_update_pos(p_list **stack)
{
	p_list	*current;
	int		i;

	if (stack == NULL || *stack == NULL)
		return ;
	i = 0;
	current = *stack;
	while (current->next != *stack)
	{
		current->position = i;
		i++;
		current = current->next;
	}
	current->position = i;
}

void	ft_update_min_max(t_stack_info *info)
{
	int		min;
	int		max;
	p_list	*current;

	if (info->stack == NULL)
		return ;
	current = info->stack;
	min = *(current->content);
	max = *(current->content);
	while (current->next != info->stack)
	{
		if (*(current->content) > max)
			max = *(current->content);
		if (*(current->content) < min)
			min = *(current->content);
		current = current->next;
	}
	if (*(current->content) > max)
		max = *(current->content);
	if (*(current->content) < min)
		min = *(current->content);
	info->min = min;
	info->max = max;
}

void	ft_set_index(t_stack_info *info)
{
	int		count;
	p_list	*current;
	p_list	*searcher;

	if (info->stack == NULL)
		return ;
	current = info->stack;
	while (1)
	{
		if (*current->content == info->min)
			current->index = 1;
		else
		{
			count = 1;
			searcher = info->stack;
			while (1)
			{
				if (*searcher->content < *current->content)
					count++;
				searcher = searcher->next;
				if (searcher == info->stack)
					break ;
			}
			current->index = count;
		}
		current = current->next;
		if (current == info->stack)
			break ;
	}
}

void	ft_set_stack(t_stack_info *info_a, t_stack_info *info_b)
{
	ft_set_index(info_a);
	info_a->letter = 'a';
	info_b->letter = 'b';
	info_a->total_len = ft_lstsize_db(info_a);
}

p_list	*ft_find_next_index(t_stack_info *info_a, p_list *current)
{
	p_list	*current_a;
	p_list	*searcher;
	int		first_node_processed;

	first_node_processed = 0;
	current_a = info_a->stack;
	searcher = NULL;
	while (current_a != info_a->stack || !first_node_processed)
	{
		first_node_processed = 1;
		if (current_a->index > current->index && searcher == NULL)
			searcher = current_a;
		if (current_a->index > current->index && \
		current_a->index < searcher->index)
			searcher = current_a;
		current_a = current_a->next;
	}
	current->target_index = searcher->index;
	current->target_pos = searcher->position;
	return (searcher);
}
