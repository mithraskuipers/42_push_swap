/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_swap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 17:56:37 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/05 18:12:03 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **head)
{
	t_stack *tmp;
	
	tmp = pop_node_front(head);
	insert_node(head, tmp, 1);
}

void	swap_b(t_stack **head)
{
	t_stack *tmp;
	
	tmp = pop_node_front(head);
	insert_node(head, tmp, 1);
}

void	swap_s(t_stack **head1, t_stack **head2)
{
	t_stack *tmp;
	
	tmp = pop_node_front(head1);
	insert_node(head1, tmp, 1);
	tmp = pop_node_front(head2);
	insert_node(head2, tmp, 1);
}
