/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 17:58:59 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/30 23:04:10 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
get_next_unidx_min() identifies the unindexed node
with the minimal value in the linked list is identified
and returned.
*/

static t_stack	*get_next_unidx_min(t_stack **head)
{
	int		min_value;
	t_stack	*tmp_node;
	t_stack	*minimum_node;
	
	tmp_node = *head;
	minimum_node = tmp_node;
	min_value = INTMAX;
	while (tmp_node)
	{
		if ((min_value > tmp_node->value) && (tmp_node->index == -1))
		{
			min_value = tmp_node->value;
			minimum_node = tmp_node;
		}
		tmp_node = tmp_node->next;
	}
	return (minimum_node);
}

/*
indexer() calls get_next_unindex_min() n times,
where n equals the number of nodes in the linked
list. Each time get_next_unindex_min() is run,
the unindexed node with the minimal value in the
linked list is identified and indexed.
*/

void			indexer(t_stack **head)
{
	int i;

	i = 0;
	while (i < n_nodes(head))
	{
		get_next_unidx_min(head)->index = i;
		i++;
	}
}
