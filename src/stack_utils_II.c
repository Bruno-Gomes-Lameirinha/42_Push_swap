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

void	ft_update_stack(t_stack_info *info_a, t_stack_info *info_b)
{
	ft_update_min_max(info_a);
	ft_update_pos(&(info_a->stack));
	info_a->len = ft_lstsize_db(info_a);
	ft_update_min_max(info_b);
	ft_update_pos(&(info_b->stack));
	info_b->len = ft_lstsize_db(info_b);
}

void	ft_init_stack_a(t_stack_info *info_a, int argc, char **argv)
{
	char	**args;
	int		i;
	t_ls_db	*new;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	while (args[i])
	{
		ft_check_push_args(args, info_a, argc);
		new = ft_lstnew_dbl(ft_atoi(args[i]));
		if (new == NULL && argc == 2)
		{
			ft_free_args(args, ft_count_args(args));
			ft_free_memory_a(info_a);
		}
		info_a->stack = ft_lstadd_back_dbl(&(info_a->stack), new);
		i++;
	}
	if (argc == 2)
		ft_free_args(args, i);
}

void	ft_free_memory_a(t_stack_info *stack_a)
{
	t_ls_db	*current;
	t_ls_db	*current_x;

	if (stack_a->stack == NULL || stack_a == NULL)
		return ;
	current = stack_a->stack->next;
	current_x = stack_a->stack->next->next;
	while (current != stack_a->stack)
	{
		free(current->content);
		current = current->next;
		free(current_x->prev);
		current_x = current->next;
	}
	free(stack_a->stack->content);
	free(stack_a->stack);
}

void	ft_free_args(char **args, int i)
{
	while (i > 0)
	{
		--i;
		free(args[i]);
	}
	free(args);
}

void	ft_error(char *msg)
{
	ft_printf ("%s\n", msg);
	exit(0);
}
