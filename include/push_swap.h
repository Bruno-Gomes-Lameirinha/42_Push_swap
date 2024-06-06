/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:00:47 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/05/07 19:34:38 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct push_list
{
	int					*content;
	int					index;
	int					cost;
	int					target_index;
	int					target_pos;
	int					position;
	struct push_list	*prev;
	struct push_list	*next;
}	p_list;

typedef struct stack_info
{
	p_list  *stack;
	int     len;
	int		total_len;
	int     min;
	int     max;
	char	letter;
}   t_stack_info;

p_list  *ft_lstadd_back_dbl(p_list **stack, p_list *new);
p_list  *ft_lstnew_dbl(int data);
void 	ft_swap(t_stack_info *info); 
void 	ft_rotate_a(t_stack_info *info);
p_list  *ft_rotate_b(t_stack_info *info);
p_list  *ft_reverse_rotate_a(t_stack_info *info);
void    ft_push_b(t_stack_info *info_a, t_stack_info *info_b);
void 	ft_lstadd_front_db(t_stack_info *info, p_list *new);
void    ft_update_pos(p_list **stack);
void    ft_update_min_max(t_stack_info *info);
void    ft_print_list(t_stack_info *info);
void 	ft_set_index(t_stack_info *info);
int		ft_lstsize_db(t_stack_info *info);
int 	ft_is_sorted(p_list *stack);
void    ft_tiny_sort(t_stack_info *info);
void    ft_update_stack(t_stack_info *info_a, t_stack_info *info_b);
p_list *ft_rotate_b(t_stack_info *info);
p_list *ft_reverse_rotate_b(t_stack_info *info);
void    ft_push_a(t_stack_info *info_a, t_stack_info *info_b);
void    ft_set_stack(t_stack_info *info_a, t_stack_info *info_b);
void    ft_get_cost(t_stack_info *info_a, t_stack_info *info_b);
p_list *ft_find_next_index(t_stack_info *info_a, p_list *current);
p_list *ft_find_min_cost_node(t_stack_info *info_b);
void	ft_make_moves_sb(t_stack_info *info_a, t_stack_info *info_b);
void	ft_make_moves_sa(t_stack_info *info_a, p_list *node);

#endif