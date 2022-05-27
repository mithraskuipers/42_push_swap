/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/27 19:44:56 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/27 21:08:54 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_env *env, int bucket_size)
{
	while (n_nodes(&env->stack_a) > 1)
	{
		put_node_upfront(env, get_min_value(&env->stack_a), bucket_size);
		if ((ps_isordered(&env->stack_a)) && \
		(env->stack_a->value > env->stack_b->value))
			break;
		push_b(env);
	}
	push_b(env);
	while (n_nodes(&env->stack_b) > 0)
	{
		put_node_upfront_b(env, get_max_value(&env->stack_b));
		push_a(env);
	}
}
