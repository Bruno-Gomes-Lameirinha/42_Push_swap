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

int main(int argc, char **argv) 
{
    t_stack_info stack_a;
    t_stack_info stack_b;
    p_list *new;
    int i;
    char **args;

    i = 0;
    stack_a.stack = NULL;
    stack_b.stack = NULL;
    if (argc < 2)
        exit(1);
    else if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
        args = &argv[1];
    
    while (args[i]) {
        new = ft_lstnew_dbl(ft_atoi(args[i]));
        stack_a.stack = ft_lstadd_back_dbl(&(stack_a.stack), new);
        i++;
    }

    ft_update_min_max(&stack_a);
    ft_set_index(&stack_a);

    ft_printf("Lista original:\n");
    ft_update_pos(&(stack_a.stack));
    ft_print_list(&stack_a);

    ft_printf("Maior valor na stack: %d\n", stack_a.max);
    ft_printf("Menor valor na stack: %d\n", stack_a.min);

    ft_swap_a(&stack_a);
    ft_update_pos(&(stack_a.stack));
    ft_printf("Depois do swap:\n");
    ft_print_list(&stack_a);

    ft_rotate_a(&stack_a);
    ft_update_pos(&(stack_a.stack));
    ft_printf("Depois do rotate:\n");
    ft_print_list(&stack_a);

    ft_rotate_a(&stack_a);
    ft_printf("Depois do rotate:\n");
    ft_update_pos(&(stack_a.stack));
    ft_print_list(&stack_a);

    ft_reverse_rotate_a(&stack_a);
    ft_printf("Depois do reverse rotate:\n");
    ft_update_pos(&(stack_a.stack));
    ft_print_list(&stack_a);

    ft_push_b(&stack_a, &stack_b);
    ft_push_b(&stack_a, &stack_b);
    ft_push_b(&stack_a, &stack_b);
    ft_push_b(&stack_a, &stack_b);
    ft_push_b(&stack_a, &stack_b);
    ft_update_pos(&(stack_a.stack));
    ft_update_pos(&(stack_b.stack));
    ft_printf("Depois do push b:\n");
    ft_printf("stack_a\n");
    ft_print_list(&stack_a);
    ft_printf("stack_b\n");
    ft_print_list(&stack_b);

    if (argc == 2)
        free(args);

    return 0;
}
