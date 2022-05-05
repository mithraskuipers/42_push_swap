/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rrotate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 18:09:30 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/05 18:14:55 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_stack **head)
{
	t_stack *tmp;

	tmp = pop_node_back(head);
	add_node_front(head, tmp);
}

void	rrotate_b(t_stack **head)
{
	t_stack *tmp;

	tmp = pop_node_back(head);
	add_node_front(head, tmp);
}

void	rrotate_s(t_stack **head1, t_stack **head2)
{
	t_stack *tmp;

	tmp = pop_node_back(head1);
	add_node_front(head1, tmp);
	tmp = pop_node_back(head2);
	add_node_front(head2, tmp);
}
