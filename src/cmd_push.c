/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_push.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 19:37:07 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/10 19:01:18 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **head1, t_stack **head2)
{
	t_stack	*tmp;
	tmp = pop_node_front(head2);
	insert_node(head1, tmp, 0);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **head1, t_stack **head2)
{
	t_stack	*tmp;
	tmp = pop_node_front(head1);
	insert_node(head2, tmp, 0);
	write(1, "pb\n", 3);
}
