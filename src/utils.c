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

void print_list(p_list *stack) {
    p_list *current;

    if (stack == NULL)
        return;

    current = stack;
    while (current->next != stack)
	{
        ft_printf("%d\n", *current->content);
        current = current->next;
	}
	ft_printf("%d\n", *current->content);
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