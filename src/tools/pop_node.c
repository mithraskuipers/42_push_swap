/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pop_node.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 10:42:32 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/01 22:56:47 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*popnode_front(t_stack **head)
{
	/*
	t_stack	*ret;
	t_stack	*tmp;

	if (*head == NULL)
		return (NULL);
	ret = *head;
	if (!ret->next)
	{
		*head = NULL;
		return (ret);
	}
	tmp = (*head);
	(*head) = (*head)->next;
	(*head)->next = tmp;
	return (ret);
	*/
	///*
	t_stack	*first;

	first = newnode((*head)->value, (*head)->index);
	first->next = NULL;
	(*head) = (*head)->next;
	return (first);
	//*/
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
