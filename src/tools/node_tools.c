/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_tools.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 12:47:46 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/01 15:42:26 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newnode(int val, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		exit(2);
	node->value = val;
	node->index = index;
	node->next = NULL;
	return (node);
}

int	n_nodes(t_stack **head)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	insert_node(t_stack **head, t_stack *new_node, int pos)
{
	t_stack	*edge_left;
	t_stack	*mem;

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
