/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_push.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 19:37:07 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/31 22:42:03 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_env *env)
{
	t_stack	*tmp;

	if (n_nodes(&env->stack_b) > 0)
	{
		tmp = popnode_front(&env->stack_b);
		insert_node(&env->stack_a, tmp, 0);
		write(1, "pa\n", 3);
	}
}

void	push_b(t_env *env)
{
	t_stack	*tmp;

	if (n_nodes(&env->stack_a) > 0)
	{
		tmp = popnode_front(&env->stack_a);
		insert_node(&env->stack_b, tmp, 0);
		write(1, "pb\n", 3);
	}
}
