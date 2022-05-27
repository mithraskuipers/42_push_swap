/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_6.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:47:48 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/27 20:52:51 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_6_helper(t_env *env)
{
	int	index;

	while (n_nodes(&env->stack_a) != 3)
	{
		index = get_idx_for_value(&env->stack_a, get_min_value(&env->stack_a));
		if (index > (n_nodes(&env->stack_a) / 2))
		{
			while (index <= (n_nodes(&env->stack_a) - 1))
			{
				rrotate_a(env);
				index++;
			}
		}
		else
		{
			while (index)
			{
				rotate_a(env);
				index--;
			}
		}
		push_b(env);
	}
}

void	sort_6(t_env *env)
{
	sort_6_helper(env);
	sort_3(env);
	push_a(env);
	push_a(env);
	push_a(env);
}
