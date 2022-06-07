/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_tools.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 12:47:46 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/07 12:53:41 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newnode(int val, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		exit(1);
	node->value = val;
	node->index = index;
	node->next = NULL;
	return (node);
}

void	addnode_end(t_stack **head, t_stack *new)
{
	t_stack	*final_element;

	if (!(*head))
	{
		*head = new;
		return ;
	}
	final_element = get_last(head);
	final_element->next = new;
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
