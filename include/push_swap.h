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
	int					position;
	struct push_list	*prev;
	struct push_list	*next;
}	p_list;

p_list	*ft_lstadd_back_dbl(p_list **stack, p_list *new);
p_list *ft_lstnew_dbl(int data, int pos);
p_list	*ft_swap_a(p_list **stack);
p_list	*ft_swap_b(p_list **stack);
p_list	*ft_swap_ss(p_list **stack_a, p_list **stack_b);
p_list	*ft_rotate_a(p_list **stack);
void	print_list(p_list *stack);
p_list 	*ft_reverse_rotate_a(p_list **stack);
p_list 	*ft_push_b(p_list **stack_a, p_list **stack_b);
void	ft_lstadd_front_db(p_list **lst, p_list *new);

#endif