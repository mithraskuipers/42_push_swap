/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_5.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:47:48 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/30 23:00:39 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_5_helper(t_env *env)
{
	int	index;

	index = get_idx_for_val(&env->stack_a, get_min_val(&env->stack_a));
	if ((index + 1) == 5)
		rrotate_a(env);
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

void	sort_5(t_env *env)
{
	sort_5_helper(env);
	sort_5_helper(env);
	sort_3(env);
	push_a(env);
	push_a(env);
}
