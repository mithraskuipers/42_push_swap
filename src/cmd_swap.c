/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_swap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 17:56:37 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/25 14:50:28 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **head)
{
	t_stack *tmp;
	
	if (n_nodes(head) > 0)
	{
		tmp = pop_node_front(head);
		insert_node(head, tmp, 1);
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_stack **head)
{
	t_stack *tmp;
	
	if (n_nodes(head) > 0)
	{
		tmp = pop_node_front(head);
		insert_node(head, tmp, 1);
		write(1, "sb\n", 3);
	}
}

void	swap_s(t_stack **head1, t_stack **head2)
{
	t_stack *tmp;
	
	tmp = pop_node_front(head1);
	insert_node(head1, tmp, 1);
	tmp = pop_node_front(head2);
	insert_node(head2, tmp, 1);
 	write(1, "ss\n", 3);
}
