#include "../include/push_swap.h"

p_list *ft_swap_a(p_list **stack) {
	p_list *first;
	p_list *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return NULL;

	first = *stack;
	second = first->next;

	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev->next = second;
	first->prev = second;

	*stack = second;

	ft_printf("sa\n");

	return *stack;
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

p_list *ft_rotate_a(p_list **stack) 
{
	p_list *first;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return NULL;
	first = *stack;
	*stack = first->next; 
	ft_printf("ra\n");
	return *stack;
}

p_list *ft_reverse_rotate_a(p_list **stack) 
{
	p_list *first;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return NULL;

	first = *stack;
	*stack = first->prev; 
	ft_printf("ra\n");

	return *stack;
}

p_list *ft_push_b(p_list **stack_a, p_list **stack_b) 
{
	p_list *node_to_push;
	p_list *new_head;

	if (stack_a == NULL || *stack_a == NULL)
		return NULL;
	node_to_push = *stack_a;
	if (node_to_push->next == node_to_push)
		new_head = NULL;
	else
	{
		new_head = node_to_push->next;
		new_head->prev = node_to_push->prev;
		new_head->next = node_to_push->next->next;
		node_to_push->prev->next = new_head;
	}
	node_to_push->next = NULL;
	node_to_push->prev = NULL;
	*stack_a = new_head;
	ft_lstadd_front_db(stack_b, node_to_push);
	*stack_b = node_to_push;
	ft_printf("pb");
	return *stack_a;
}

