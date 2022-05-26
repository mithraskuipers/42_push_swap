/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_5.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:47:48 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/26 17:54:16 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_5_helper(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	index = get_idx_for_value(stack_a, get_min_value(stack_a));
	if ((index + 1) == 5)
		rrotate_a(stack_a);
	else
	{
		while (index)
		{
			rotate_a(stack_a);
			index--;
		}
	}
	push_b(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	sort_5_helper(stack_a, stack_b);
	sort_5_helper(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
