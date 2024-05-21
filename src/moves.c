#include "../include/push_swap.h"

p_list	*ft_swap_a(p_list **stack)
{
    p_list *first;
    p_list *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return NULL;

    first = *stack;
    second = first->next;

    first->next = second->next;
    second->next = first;
    second->prev = first->prev;
    first->prev = second;

    if (first->next != NULL)
        first->next->prev = first;

    *stack = second;
    ft_printf("sa\n");

    return (*stack);
}

p_list	*ft_swap_b(p_list **stack)
{
    p_list *first;
    p_list *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return NULL;

    first = *stack;
    second = first->next;

    first->next = second->next;
    second->next = first;
    second->prev = first->prev;
    first->prev = second;

    if (first->next != NULL)
        first->next->prev = first;

    *stack = second;
    ft_printf("sb\n");

    return (*stack);
}

/*p_list	*ft_swap_ss(p_list **stack_a, p_list **stack_b)
{
    ft_swap_b(p_list **stack);
    ft_swap_b(p_list **stack);
*/
