/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:30:13 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/06/10 19:08:48 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_ls_db	*ft_lstadd_back_dbl(t_ls_db **stack, t_ls_db *new)
{
	t_ls_db	*last;

	if (stack == NULL || new == NULL)
		return (NULL);
	if (*stack == NULL)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		last = (*stack)->prev;
		last->next = new;
		new->prev = last;
		new->next = *stack;
		(*stack)->prev = new;
	}
	return (*stack);
}

t_ls_db	*ft_lstnew_dbl(int data)
{
	t_ls_db	*new_node;
	int		*ptr;

	new_node = malloc(sizeof(t_ls_db));
	if (new_node == NULL)
		return (NULL);
	ptr = malloc(sizeof(int));
	if (ptr == NULL)
	{
		free(new_node);
		return (NULL);
	}
	*ptr = data;
	new_node->content = ptr;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_lstadd_front_db(t_stack_info *info, t_ls_db *new)
{
	t_ls_db	*last;

	if (new != NULL)
	{
		if (info->stack == NULL)
		{
			new->next = new;
			new->prev = new;
			info->stack = new;
		}
		else
		{
			last = info->stack->prev;
			new->next = info->stack;
			new->prev = last;
			last->next = new;
			info->stack->prev = new;
			info->stack = new;
		}
	}
}

int	ft_lstsize_db(t_stack_info *info)
{
	int		i;
	t_ls_db	*current;

	current = info->stack;
	i = 0;
	if (info->stack != NULL)
	{
		while (current->next != info->stack)
		{
			current = current->next;
			i++;
		}
		i++;
	}
	return (i);
}
