/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_4.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:47:48 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/27 20:52:16 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_env *env)
{
	int	index;

	index = get_idx_for_value(&env->stack_a, get_min_value(&env->stack_a));
	if ((index + 1) == 4)
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
	sort_3(env);
	push_a(env);
}
