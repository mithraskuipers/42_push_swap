/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 12:47:46 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/05 12:53:46 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_new_node(int value, int index)
{
	t_stack	*node;

	node = malloc(1 * sizeof(t_stack));
	node->value = value;
	node->index = index;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

t_stack *pop_node_front(t_stack **head)
{
	t_stack *first;
	first = create_new_node((*head)->value, (*head)->index);
	first->next = NULL;
	(*head) = (*head)->next;
	return (first);
}

void	insert_node(t_stack **head, t_stack *new_node, int pos)
{
	t_stack	*edge_left;
	t_stack *mem;
	edge_left = *head;
	if (pos == 0)
	{
		new_node->next = edge_left;
		*head = new_node;
	}
	else
	{
		while ((pos > 1) && (edge_left->next))
		{
			edge_left = edge_left->next;
			pos--;
		}
		mem = edge_left->next;
		edge_left->next = new_node;
		new_node->next = mem;
	}
}

t_stack	*pop_node_back(t_stack **head)
{
	t_stack *tmp;
	t_stack	*popped;
	
	tmp = *head;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	popped = tmp->next;
	tmp->next = NULL;
	return (popped);
}

int		n_nodes(t_stack **head)
{
	int	i;
	t_stack *tmp;

	i = 0;
	tmp = *head;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	remove_node(t_stack **head, int pos)
{
	t_stack	*edge_left;
	t_stack *right;

	edge_left = *head;
	if (pos > n_nodes(head))
		pos = n_nodes(head);
	if (pos == 0)
		(*head) = (*head)->next;
	else
	{
		while ((pos > 1) && (edge_left->next))
		{
			edge_left = edge_left->next;
			pos--;
		}
		right = edge_left->next->next;
		edge_left->next = right;
	}
}

void	print_forwards(t_stack **head)
{
	while (*head)
	{
		printf("index [%d] value %d \n", (*head)->index, (*head)->value);
		(*head) = (*head)->next;
	}
}
