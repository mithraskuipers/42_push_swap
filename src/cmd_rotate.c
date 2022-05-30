/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 16:00:03 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/31 00:34:20 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"












void	addnode_back(t_stack **head, t_stack *new_node)
{
	t_stack *tmp;

	tmp = (*head);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}










void	rotate_a(t_env *env)
{
	t_stack	*tmp;

	if (n_nodes(&env->stack_a) > 0)
	{
		tmp = popnode_front(&env->stack_a);
		addnode_back(&env->stack_a, tmp);
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_env *env)
{
	t_stack	*tmp;

	if (n_nodes(&env->stack_b) > 0)
	{
		tmp = popnode_front(&env->stack_b);
		addnode_back(&env->stack_b, tmp);
		write(1, "rb\n", 3);
	}
}

void	rotate_s(t_env *env)
{
	t_stack	*tmp;

	if ((n_nodes(&env->stack_a) > 0) && (n_nodes(&env->stack_b) > 0))
	{
		tmp = popnode_front(&env->stack_a);
		addnode_back(&env->stack_a, tmp);
		tmp = popnode_front(&env->stack_b);
		addnode_back(&env->stack_b, tmp);
		write(1, "rr\n", 3);
	}
}
