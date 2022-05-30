/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_radix.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/27 19:44:56 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/30 08:11:24 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
get_next_unindex_min() identifies the unindexed node
with the minimal value in the linked list is identified
and returned.
*/

t_stack	*get_next_unindex_min(t_stack **head)
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

void	indexer(t_stack **head)
{
	int i;

	i = 0;
	while (i < n_nodes(head))
	{
		get_next_unindex_min(head)->index = i;
		i++;
	}
}

/*
sort_radix(), intuitively named, implements the radix sorting algorithm.
The twist is here that the algorithm has been used on the indices of the nodes
instead of the values (i.e. user input). Here, the indices are simply a set of
numbers that are used to order the collection of values from smallest to 
largest. As a consequence, when the nodes are sorted on their index value,
the used inputted list of numbers has been sorted from smallest to largest.
The reason why I applied radix to the indices instead of values is that it makes
radix more efficient when working with non-contiguous sequences of randomized 
numbers. By definition, working with indices means that you work with contiguous
sequences of randomized numbers (i.e. there are no "gaps" between the numbers;
e.g., 0-1-2-3-4, vs 0-5-11-39-83).
*/

void	sort_radix(t_env *env)
{
	int	len;
	int	node;
	int	significance;
	int	bitshifted_index;

	significance = 0;
	indexer(&env->stack_a);
	len = n_nodes(&env->stack_a);
	while (ps_isordered(&env->stack_a) == 0)
	{
		node = 0;
		while (node < len)
		{
			bitshifted_index = (env->stack_a)->index >> significance;
			if ((bitshifted_index & 1) == 1)
				rotate_a(env);
			else
				push_b(env);
			node++;
		}
		while(n_nodes(&env->stack_b) > 0)
			push_a(env);
		significance++;
	}
}



/*
void	sort_big(t_env *env)
{

	t_stack	*tmp;
	tmp = env->stack_a;
	while (tmp)
	{
		tmp->value = tmp->index;
		tmp = tmp->next;
	}

	size_t		length;
	size_t		i;
	size_t		j;
	int			k;

	length = n_nodes(&env->stack_a);
	i = 0;
	while (!ps_isordered(&env->stack_a))
	{
		j = 0;
		while (j < length)
		{
			k = (env->stack_a)->value >> i;
			if ((k & 1) == 1)
				rotate_a(env);
			else
				push_b(env);
			j++;
		}
		while(n_nodes(&env->stack_b) > 0)
		{
			push_a(env);
		}
		i++;
	}
}
*/