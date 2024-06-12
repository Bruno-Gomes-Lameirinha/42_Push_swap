/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:02:21 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/06/10 20:05:43 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_get_cost(t_stack_info *info_a, t_stack_info *info_b)
{
	t_ls_db	*current_b;
	t_ls_db	*next_index;
	int		first_node_processed;

	if (info_b->stack == NULL)
		return ;
	current_b = info_b->stack;
	first_node_processed = 0;
	while (current_b != info_b->stack || !first_node_processed)
	{
		first_node_processed = 1;
		next_index = ft_find_next_index(info_a, current_b);
		if (next_index->position < (info_a->len / 2))
			next_index->cost = next_index->position;
		else
			next_index->cost = (info_a->len - next_index->position) + 1;
		if (current_b->position < (info_b->len / 2))
			current_b->cost = ((current_b->position) + next_index->cost);
		else
			current_b->cost = ((info_b->len - current_b->position) \
			+ next_index->cost);
		current_b = current_b->next;
	}
}

t_ls_db	*ft_find_min_cost_node(t_stack_info *info_b)
{
	t_ls_db	*current;
	t_ls_db	*searcher;
	int		first_node_processed;

	first_node_processed = 0;
	current = info_b->stack;
	searcher = NULL;
	while (current != info_b->stack || !first_node_processed)
	{
		first_node_processed = 1;
		if (searcher == NULL || searcher->cost > current->cost)
			searcher = current;
		current = current->next;
	}
	return (searcher);
}

t_ls_db	*ft_find_index_one(t_stack_info *info_a)
{
	t_ls_db	*current_a;
	t_ls_db	*searcher;
	int		first_node_processed;

	first_node_processed = 0;
	current_a = info_a->stack;
	searcher = NULL;
	while (current_a != info_a->stack || !first_node_processed)
	{
		first_node_processed = 1;
		if (current_a->index == 1)
			searcher = current_a;
		current_a = current_a->next;
	}
	return (searcher);
}

void	ft_finish_stack(t_stack_info *stack_a)
{
	t_ls_db	*node_index_one;

	node_index_one = ft_find_index_one(stack_a);
	ft_last_moves_sa(stack_a, node_index_one);
}

void	ft_last_moves_sa(t_stack_info *info_a, t_ls_db *node)
{
	int	moves;

	if (node->position <= info_a->len / 2)
	{
		moves = node->position;
		while (moves > 0)
		{
			ft_rotate_a(info_a);
			moves--;
		}
	}
	else
	{
		moves = ((info_a->len - node->position));
		while (moves > 0)
		{
			ft_reverse_rotate_a(info_a);
			moves--;
		}
	}
}
