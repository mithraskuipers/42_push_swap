/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:47:48 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/27 20:42:59 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_env *env)
{
	t_stack	*start;
	t_stack	*middle;
	t_stack	*end;

	t_stack	*head;

	head = env->stack_a;
	
	start = (head);
	middle = (head)->next;
	end = (head)->next->next;
	if (middle->value < start->value && start->value < end->value)
		swap_a(env);
	else if (end->value < middle->value && middle->value < start->value)
	{
		swap_a(env);
		rrotate_a(env);
	}
	else if (middle->value < end->value && end->value < start->value)
		rotate_a(env);
	else if (start->value < end->value && end->value < middle->value)
	{
		swap_a(env);
		rotate_a(env);
	}
	else if (end->value < start->value && start->value < middle->value)
		rrotate_a(env);
}
