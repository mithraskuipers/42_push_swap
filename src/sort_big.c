/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/27 19:44:56 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/28 15:16:46 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_env *env, int bucket_size)
{
	while (n_nodes(&env->stack_a) != 0)
	{
		put_minnode_upfront_a(env, bucket_size);
		push_b(env);
		//if ((ps_isordered(&env->stack_a)) && \ // a is gesorteerd
		//(env->stack_a->value < env->stack_b->value))
		//	break;
		if (ps_isordered(&env->stack_a) && \
		(env->stack_a->value > get_max_value(&env->stack_b)))
			break;
	}
	//while (n_nodes(&env->stack_a) != 0)
	//	push_b(env);
	// dit stuk klopt!
	while (n_nodes(&env->stack_b) > 0)
	{
		put_maxnode_upfront_b(env);
		push_a(env);
	}
}

void	put_minnode_upfront_a(t_env *env, int bucket_size)
{
	int	x;
	int	y;
	int	min_val;

	min_val = get_min_value(&env->stack_a);
	while (TRUE)
	{
		//if (INTMIN == min_val)
		//	return ;
		if ((min_val - bucket_size) <= env->stack_a->value && \
		(min_val + bucket_size) >= env->stack_a->value)
			return ;
		x = get_idx_for_value(&env->stack_a, min_val);
		y = n_nodes(&env->stack_a) / 2;
		if (x < y)
			rotate_a(env);
		else
			rrotate_a(env);
	}
}

void	put_maxnode_upfront_b(t_env *env)
{
	int	x;
	int	y;
	int	max_val;
	
	max_val = get_max_value(&env->stack_b);
	while (TRUE)
	{
		if (env->stack_b->value == max_val)
			return ;
		if (env->stack_b->next && env->stack_b->next->value == max_val)
			swap_b(env);
		else
		{
			x = get_idx_for_value(&env->stack_b, max_val);
			y = n_nodes(&env->stack_b) / 2;
			if (x < y)
				rotate_b(env);
			else
				rrotate_b(env);
		}
	}
}
