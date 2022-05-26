/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_6.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:47:48 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/26 17:54:32 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_6_helper(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	while (n_nodes(stack_a) != 3)
	{
		index = get_idx_for_value(stack_a, get_min_value(stack_a));
		if (index > (n_nodes(stack_a) / 2))
		{
			while (index <= (n_nodes(stack_a) - 1))
			{
				rrotate_a(stack_a);
				index++;
			}
		}
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
}

void	sort_6(t_stack **stack_a, t_stack **stack_b)
{
	sort_6_helper(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
