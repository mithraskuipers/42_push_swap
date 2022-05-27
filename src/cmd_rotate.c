/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 16:00:03 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/27 21:12:05 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_env *env)
{
	t_stack	*tmp;

	if (n_nodes(&env->stack_a) > 0)
	{
		tmp = pop_node_front(&env->stack_a);
		add_node_back(&env->stack_a, tmp);
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_env *env)
{
	t_stack	*tmp;

	if (n_nodes(&env->stack_b) > 0)
	{
		tmp = pop_node_front(&env->stack_b);
		add_node_back(&env->stack_b, tmp);
		write(1, "rb\n", 3);
	}
}

void	rotate_s(t_env *env)
{
	t_stack	*tmp;

	if ((n_nodes(&env->stack_a) > 0) && (n_nodes(&env->stack_b) > 0))
	{
		tmp = pop_node_front(&env->stack_a);
		add_node_back(&env->stack_a, tmp);
		tmp = pop_node_front(&env->stack_b);
		add_node_back(&env->stack_b, tmp);
		write(1, "rr\n", 3);
	}
}
