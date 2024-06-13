/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:00:47 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/06/10 20:16:20 by bgomes-l         ###   ########.fr       */
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
}	t_ls_db;

typedef struct stack_info
{
	t_ls_db	*stack;
	int		len;
	int		args;
	int		total_len;
	int		min;
	int		max;
	char	letter;
}	t_stack_info;

t_ls_db	*ft_lstadd_back_dbl(t_ls_db **stack, t_ls_db *new);
t_ls_db	*ft_lstnew_dbl(int data);
void	ft_swap(t_stack_info *info);
void	ft_rotate_a(t_stack_info *info);
t_ls_db	*ft_rotate_b(t_stack_info *info);
t_ls_db	*ft_reverse_rotate_a(t_stack_info *info);
void	ft_push_b(t_stack_info *info_a, t_stack_info *info_b);
void	ft_lstadd_front_db(t_stack_info *info, t_ls_db *new);
void	ft_update_pos(t_ls_db **stack);
void	ft_update_min_max(t_stack_info *info);
void	ft_print_list(t_stack_info *info);
void	ft_set_index(t_stack_info *info);
int		ft_lstsize_db(t_stack_info *info);
int		ft_is_sorted(t_ls_db *stack);
void	ft_tiny_sort(t_stack_info *info);
void	ft_update_stack(t_stack_info *info_a, t_stack_info *info_b);
t_ls_db	*ft_rotate_b(t_stack_info *info);
t_ls_db	*ft_reverse_rotate_b(t_stack_info *info);
void	ft_push_a(t_stack_info *info_a, t_stack_info *info_b);
void	ft_set_stack(t_stack_info *info_a, t_stack_info *info_b);
void	ft_get_cost(t_stack_info *info_a, t_stack_info *info_b);
t_ls_db	*ft_find_next_index(t_stack_info *info_a, t_ls_db *current);
t_ls_db	*ft_find_min_cost_node(t_stack_info *info_b);
t_ls_db	*ft_find_index_one(t_stack_info *info_a);
void	ft_finish_stack(t_stack_info *stack_a);
void	ft_last_moves_sa(t_stack_info *info_a, t_ls_db *node);
void	ft_rotate_both(t_stack_info *stack_a, t_stack_info *stack_b);
void	ft_reverse_rotate_both(t_stack_info *stack_a, t_stack_info *stack_b);
void	ft_make_moves(t_stack_info *info_a, t_stack_info *info_b);
int		ft_calculate_moves_a(t_stack_info *info, int target_pos);
int		ft_calculate_moves_b(t_stack_info *info, int position);
void	ft_execute_combined_moves(t_stack_info *info_a, \
t_stack_info *info_b, int *moves_a, int *moves_b);
void	ft_finalize_moves_a(t_stack_info *info_a, \
t_ls_db *node_min_cost, int moves_a);
void	ft_finalize_moves_b(t_stack_info *info_b, \
t_ls_db *node_min_cost, int moves_b);
void	ft_init_stack_a(t_stack_info *info_a, int argc, char **argv);
void	ft_send_nodes_to_stack_b(t_stack_info *stack_a, t_stack_info *stack_b);
void	ft_free_memory_a(t_stack_info *stack_a);
void	ft_free_args(char **args, int i);
int		ft_num_is_repeated(int num, char **argv, int i);
void	ft_error(char *msg);
void	ft_check_push_args(char **args, t_stack_info *info_a, int argc);
int		ft_is_num(char *num);
int		ft_count_args(char **args);

#endif
