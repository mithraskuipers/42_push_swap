/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_node.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 10:50:18 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/31 10:50:32 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addnode_front(t_stack **head, t_stack *new_node)
{
	t_stack	*tmp;

	tmp = *head;
	new_node->next = tmp;
	*head = new_node;
}

void	addnode_end(t_stack **head, t_stack *new)
{
	t_stack	*final_element;

	if (!(*head))
	{
		*head = new;
		return ;
	}
	final_element = get_last(*head);
	final_element->next = new;
}
