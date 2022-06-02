/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pop_node.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 10:42:32 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/02 10:58:50 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*popnode_front(t_stack **head)
{
	t_stack	*first;

	first = newnode((*head)->value, (*head)->index);
	first->next = NULL;
	(*head) = (*head)->next;
	return (first);
}

t_stack	*popnode_end(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*popped;

	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	popped = tmp->next;
	tmp->next = NULL;
	return (popped);
}
