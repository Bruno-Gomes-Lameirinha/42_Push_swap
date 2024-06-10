/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_II.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:30:40 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/06/10 20:14:43 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_calculate_moves_b(t_stack_info *info, int position)
{
	if (position <= (info->len / 2))
		return (position);
	else
		return (info->len - position);
}

int	ft_calculate_moves_a(t_stack_info *info, int target_pos)
{
	if (target_pos <= (info->len / 2))
		return (target_pos);
	else
		return (info->len - target_pos);
}

void	ft_execute_combined_moves(t_stack_info *info_a, t_stack_info *info_b, \
int *moves_a, int *moves_b)
{
	p_list	*node_min_cost;

	node_min_cost = ft_find_min_cost_node(info_b);
	while (*moves_a > 0 && *moves_b > 0)
	{
		if (node_min_cost->position <= (info_b->len / 2) && \
		node_min_cost->target_pos <= (info_a->len / 2))
		{
			ft_rotate_both(info_a, info_b);
			(*moves_a)--;
			(*moves_b)--;
		}
		else if (node_min_cost->position > (info_b->len / 2) && \
		node_min_cost->target_pos > (info_a->len / 2))
		{
			ft_reverse_rotate_both(info_a, info_b);
			(*moves_a)--;
			(*moves_b)--;
		}
		else
			break ;
	}
}

void	ft_finalize_moves_a(t_stack_info *info_a, \
p_list *node_min_cost, int moves_a)
{
	while (moves_a > 0)
	{
		if (node_min_cost->target_pos <= info_a->len / 2)
			ft_rotate_a(info_a);
		else
			ft_reverse_rotate_a(info_a);
		moves_a--;
	}
}

void	ft_finalize_moves_b(t_stack_info *info_b, \
p_list *node_min_cost, int moves_b)
{
	while (moves_b > 0)
	{
		if (node_min_cost->position <= (info_b->len / 2))
			ft_rotate_b(info_b);
		else
			ft_reverse_rotate_b(info_b);
		moves_b--;
	}
}
