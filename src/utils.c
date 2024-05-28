#include "../include/push_swap.h"

p_list *ft_lstadd_back_dbl(p_list **stack, p_list *new) {
    p_list *last;

    if (stack == NULL || new == NULL)
        return NULL;

    if (*stack == NULL) {
        *stack = new;
        new->next = new;
        new->prev = new;
    } else {
        last = (*stack)->prev;
        last->next = new;
        new->prev = last;
        new->next = *stack;
        (*stack)->prev = new;
    }
    return *stack;
}

p_list *ft_lstnew_dbl(int data) {
    p_list *new_node;
    int *ptr;

    new_node = malloc(sizeof(p_list));
    if (new_node == NULL)
        return NULL;
    ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        free(new_node);
        return NULL;
    }
    *ptr = data;
    new_node->content = ptr;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void ft_print_list(t_stack_info *info) 
{
    p_list *current;

    if (info->stack == NULL)
        return;

    current = info->stack;
    while (current->next != info->stack)
    {
        ft_printf("%d  %d  index:%d\n", *current->content, current->position, current->index);
        current = current->next;
    }
    ft_printf("%d  %d  index:%d\n", *current->content, current->position, current->index);
}

void ft_lstadd_front_db(p_list **lst, p_list *new) 
{
    p_list *last;

    if (new != NULL) {
        if (*lst == NULL) {
            new->next = new;
            new->prev = new;
            *lst = new;
        } else {
            last = (*lst)->prev;
            new->prev = last;
            last->next = new;
            last->prev = (*lst)->prev->prev;
            new->next = (*lst);
            *lst = new;
        }
    }
}


void ft_update_pos(p_list **stack) {
    p_list *current;
    int i;

    if (stack == NULL || *stack == NULL)
        return;

    i = 1;
    current = *stack;
    while (current->next != *stack) {
        current->position = i;
        i++;
        current = current->next;
    }
    current->position = i;
}

void ft_update_min_max(t_stack_info *info)
{
    int min;
    int max;

    if (info->stack == NULL)
        return;
    p_list *current = info->stack;
    min = *(current->content);
    max = *(current->content);

    while (current->next != info->stack)
    {
        if (*(current->content) > max)
            max = *(current->content);
        if (*(current->content) < min)
            min = *(current->content);
        current = current->next;
    }
    if (*(current->content) > max)
        max = *(current->content);
    if (*(current->content) < min)
        min = *(current->content);

    info->min = min;
    info->max = max;
}

void ft_set_index(t_stack_info *info)
{
    int count;
    p_list *current;
    p_list *searcher;

    if (info->stack == NULL)
        return;
    current = info->stack;
    while (1)
    {
        if (*current->content == info->min)
            current->index = 1;
        else
        {
            count = 1;
            searcher = info->stack;
            while (1)
            {
                if (*searcher->content < *current->content)
                    count++;
                searcher = searcher->next;
                if (searcher == info->stack)
                    break;
            }
            current->index = count;
        }
        current = current->next;
        if (current == info->stack)
            break;
    }
}

