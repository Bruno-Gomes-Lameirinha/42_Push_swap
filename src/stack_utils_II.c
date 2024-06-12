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
	p_list	*new;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	while (args[i])
	{
		new = ft_lstnew_dbl(ft_atoi(args[i]));
		info_a->stack = ft_lstadd_back_dbl(&(info_a->stack), new);
		i++;
	}
	if (argc == 2)
		free(args);
}
