/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_push.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 19:37:07 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/07 12:25:20 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_env *env)
{
	t_stack	*buff;

	if (n_nodes(&env->stack_b) == 0) // node size
		return ;
	buff = env->stack_b;
	env->stack_b = env->stack_b->next;
	buff->next = env->stack_a;
	env->stack_a = buff;
	write(1, "pa\n", 3);
}

void	push_b(t_env *env)
{
	t_stack	*buff;

	if (n_nodes(&env->stack_a) == 0) // node size
		return ;
	buff = env->stack_a;
	env->stack_a = env->stack_a->next;
	buff->next = env->stack_b;
	env->stack_b = buff;
	write(1, "pb\n", 3);
}
