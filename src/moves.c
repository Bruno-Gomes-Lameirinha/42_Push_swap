#include "../include/push_swap.h"

void    ft_swap(t_stack_info *info) 
{
    p_list *first;
    p_list *second;

    if (info == NULL || info->stack == NULL || info->stack->next == NULL)
        return;
    first = info->stack;
    second = first->next;
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    second->next = first;
    second->prev = first->prev;
    first->prev->next = second;
    first->prev = second;
    info->stack = second;
    if (info->letter == 'a')
        ft_printf("sa\n");
    else
        ft_printf("sb\n");
}

void    ft_rotate_a(t_stack_info *info) 
{
    p_list *new_head;

    if (info == NULL || info->stack == NULL || info->stack->next == NULL)
        return;

    new_head = info->stack->next;
    info->stack = new_head;

    ft_printf("ra\n");
}

p_list *ft_rotate_b(t_stack_info *info) 
{
    p_list *first;

    if (info == NULL || info->stack == NULL || info->stack->next == NULL)
        return NULL;

    first = info->stack;
    info->stack = first->next;

    ft_printf("rb\n");
    return info->stack;
}

p_list *ft_reverse_rotate_a(t_stack_info *info) 
{
    p_list *first;

    if (info == NULL || info->stack == NULL || info->stack->next == NULL)
        return NULL;

    first = info->stack;
    info->stack = first->prev;

    ft_printf("rra\n");
    return info->stack;
}

p_list *ft_reverse_rotate_b(t_stack_info *info) 
{
    p_list *first;

    if (info == NULL || info->stack == NULL || info->stack->next == NULL)
        return NULL;

    first = info->stack;
    info->stack = first->prev;

    ft_printf("rrb\n");
    return info->stack;
}


p_list *ft_push_b(t_stack_info *info_a, t_stack_info *info_b) {
    p_list *node_to_push;
    p_list *new_head;

    if (info_a == NULL || info_a->stack == NULL)
        return NULL;

    node_to_push = info_a->stack;
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
    info_a->stack = new_head;
    ft_lstadd_front_db(&(info_b->stack), node_to_push);
    info_b->stack = node_to_push;
    ft_printf("pb\n");
    return info_a->stack;
}

p_list *ft_push_a(t_stack_info *info_a, t_stack_info *info_b) {
    p_list *node_to_push;
    p_list *new_head;

    if (info_a == NULL || info_a->stack == NULL)
        return NULL;

    node_to_push = info_b->stack;
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
    info_b->stack = new_head;
    ft_lstadd_front_db(&(info_a->stack), node_to_push);
    info_a->stack = node_to_push;
    ft_printf("pa\n");
    return info_b->stack;
}
