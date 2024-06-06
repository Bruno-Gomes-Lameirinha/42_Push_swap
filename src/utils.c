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
		ft_printf("content %d  pos: %d  index: %d cost: %d  target: %d\n", *current->content, current->position, current->index, current->cost, current->target_index);
		current = current->next;
	}
	ft_printf("content %d  pos: %d  index: %d cost: %d target: %d\n", *current->content, current->position, current->index, current->cost, current->target_index);
}

void    ft_lstadd_front_db(t_stack_info *info, p_list *new) 
{
	p_list *last;

	if (new != NULL) 
	{
		if (info->stack == NULL) {
			new->next = new;
			new->prev = new;
			info->stack = new;
		} else 
		{
			last = info->stack->prev;
			new->next = info->stack;
			new->prev = last;
			last->next = new;
			info->stack->prev = new;
			info->stack = new;
		}
	}
}


void ft_update_pos(p_list **stack) {
	p_list *current;
	int i;

	if (stack == NULL || *stack == NULL)
		return;

	i = 0;
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
	p_list *current;

	if (info->stack == NULL)
		return;
	current = info->stack;
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

int	ft_lstsize_db(t_stack_info *info)
{
	int		i;
	p_list	*current;

	current = info->stack;
	i = 0;
	if (info->stack != NULL)
	{
		while (current->next != info->stack)
		{
			current = current->next;
			i++;
		}
		i++;
	}
	return (i);
}

void    ft_set_stack(t_stack_info *info_a, t_stack_info *info_b)
{
	ft_set_index(info_a);
	info_a->letter = 'a';
	info_b->letter = 'b';
	info_a->total_len = ft_lstsize_db(info_a);
}
void    ft_get_cost(t_stack_info *info_a, t_stack_info *info_b)
{
	p_list	*current_b;
	p_list	*next_index;
	int     first_node_processed;

	if(info_b->stack == NULL)
		return;
	current_b = info_b->stack;
	first_node_processed = 0;
	// custo de b é se a position fo menor do que len / 2 então o custo é a position
	// se a position for maior que len / 2 aí o custo é len - position + 1 (o mov de jogar para topo).
	while (current_b != info_b->stack || !first_node_processed)
	{
		first_node_processed = 1; 
		next_index = ft_find_next_index(info_a, current_b);
		if(next_index->position < (info_a->len / 2))
			next_index->cost = next_index->position;
		else
			next_index->cost = info_a->len - next_index->position;
		if(current_b->position < (info_b->len / 2))
			current_b->cost = ((current_b->position) + next_index->cost);
		else
			current_b->cost = ((info_b->len - current_b->position)+ next_index->cost);
		current_b = current_b->next;
	}
}
p_list *ft_find_next_index(t_stack_info *info_a, p_list *current)
{
	p_list *current_a;
	p_list *searcher;
	int	first_node_processed; 

	first_node_processed = 0; 
	current_a = info_a->stack;
	searcher = NULL;
	while (current_a != info_a->stack || !first_node_processed)
	{
		first_node_processed = 1;
		if (current_a->index > current->index && searcher == NULL)
			searcher = current_a;
		if (current_a->index > current->index && current_a->index < searcher->index)
			searcher = current_a;
		current_a = current_a->next;
	}
	current->target_index = searcher->index;
	current->target_pos = searcher->position;
	return(searcher);
}
p_list *ft_find_min_cost_node(t_stack_info *info_b)
{
	p_list *current;
	p_list *searcher;
	int     first_node_processed;

	first_node_processed = 0;
	current = info_b->stack;
	searcher = NULL;
	while (current != info_b->stack || !first_node_processed)
	{
		first_node_processed = 1;
		if (searcher == NULL)
			searcher = current;
		if (searcher->cost > current->cost)
			searcher = current;
		current = current->next;
	}
	return (current);
}
void	ft_make_moves_sb(t_stack_info *info_a, t_stack_info *info_b)
{
	p_list *node_min_cost;
	int moves;

	node_min_cost = (ft_find_min_cost_node(info_b));
	ft_make_moves_sa(info_a, node_min_cost);
	if (node_min_cost->position <= (info_b->len / 2))
	{
		moves = node_min_cost->position;
		while(moves > 0)
		{
			ft_rotate_b(info_b);
			moves--;
		}
		ft_push_a(info_a, info_b);
	}
	else
	{
		moves = ((info_b->len - node_min_cost->position));
		while(moves > 0)
		{
			ft_reverse_rotate_b(info_b);
			moves--;
		}
		ft_push_a(info_a, info_b);
	}
}
void	ft_make_moves_sa(t_stack_info *info_a, p_list *node)
{
	int moves;

	if(node->target_pos <= info_a->len/2)
	{
		moves = node->target_pos;
		while(moves > 0)
		{
			ft_rotate_a(info_a);
			moves--;
		}
	}
	else
	{
		moves = ((info_a->len - node->target_pos));
		while(moves > 0)
		{
			ft_reverse_rotate_a(info_a);
			moves--;
		}
	}
}