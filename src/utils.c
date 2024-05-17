#include "../include/push_swap.h"

p_list	*ft_lstadd_back_dbl(p_list **stack, p_list *new)
{
	p_list	*head;
	p_list	*start;
	
	
	if (*stack != NULL)
	{
		head = *stack;
		start = *stack;
		while (start->next)
			start = start->next;
		start->next = new;
		new->prev = start;
	}
	else
		head = new;
	return (head);
}
p_list	*ft_lstnew_dbl(int data)
{
	p_list	*new_node;
	int 	*ptr;

	new_node = malloc (sizeof (p_list));
	if (new_node == NULL)
		return (NULL);
	ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        free(new_node);
        return NULL;
    }
    *ptr = data;
    new_node->content = ptr;
	new_node->next = NULL;
	new_node->prev = NULL;
	return(new_node);
}


