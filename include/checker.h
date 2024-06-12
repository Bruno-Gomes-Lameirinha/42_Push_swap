#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "push_swap.h"

void		ft_exec_instruc(char *instruction, t_stack_info *stack_a, \
t_stack_info *stack_b);
int		ft_is_sorted_checker(t_ls_db *stack);
void		ft_push_b_bonus(t_stack_info *info_a, t_stack_info *info_b);
void		ft_push_a_bonus(t_stack_info *info_a, t_stack_info *info_b);
void		ft_rotate_both_bonus(t_stack_info *stack_a, t_stack_info *stack_b);
void		ft_reverse_rotate_both_bonus(t_stack_info *stack_a, \
t_stack_info *stack_b);
void		ft_swap_bonus(t_stack_info *info);
void		ft_rotate_a_bonus(t_stack_info *info);
t_ls_db	*ft_rotate_b_bonus(t_stack_info *info);
t_ls_db	*ft_reverse_rotate_a_bonus(t_stack_info *info);
t_ls_db	*ft_reverse_rotate_b_bonus(t_stack_info *info);

#endif
