/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:34:16 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/05/07 20:19:25 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	p_list	*stack_a;
	p_list	*current;
	p_list	*new;
	int i;
	char	**args;

	i = 0;
	stack_a = NULL ;
	current = NULL;
	if (argc < 2)
		exit(1);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	while (args[i])
	{
		new = ft_lstnew_dbl(ft_atoi(args[i]));
		stack_a = ft_lstadd_back_dbl(&stack_a, new);
		i++;
	}
	current = stack_a;
	while (current->next != NULL)
	{
		ft_printf("%d\n", *current->content);
		current = current->next;
	}
	ft_printf("%d\n", *current->content);
	/*
	while (current->prev != NULL)
	{
		ft_printf("%d\n", *current->prev->content);
		current = current->prev;
	}
	*/
	ft_swap_a(&stack_a);
	ft_printf("Depois do swap\n");
	current = stack_a;
	while (current->next != NULL)
	{
		ft_printf("%d\n", *current->content);
		current = current->next;
	}
	ft_printf("%d\n", *current->content);

	if (argc == 2)
		free(args);
	free(stack_a);
	return (0);
}
