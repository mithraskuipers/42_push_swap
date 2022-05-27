/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rrotate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 18:09:30 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/27 21:12:32 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_env *env)
{
	t_stack	*tmp;

	tmp = pop_node_back(&env->stack_a);
	add_node_front(&env->stack_a, tmp);
	write(1, "rra\n", 4);
}

void	rrotate_b(t_env *env)
{
	t_stack	*tmp;

	tmp = pop_node_back(&env->stack_b);
	add_node_front(&env->stack_b, tmp);
	write(1, "rrb\n", 4);
}

void	rrotate_s(t_env *env)
{
	t_stack	*tmp;

	tmp = pop_node_back(&env->stack_a);
	add_node_front(&env->stack_a, tmp);
	tmp = pop_node_back(&env->stack_b);
	add_node_front(&env->stack_b, tmp);
	write(1, "rrr\n", 4);
}
