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
    struct push_list	*prev;
	struct push_list	*next;
}	p_list;

p_list	*ft_lstadd_back_dbl(p_list **stack, p_list *new);
p_list	*ft_lstnew_dbl(int data);

#endif