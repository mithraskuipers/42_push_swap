/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_swap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 17:56:37 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/06 19:10:43 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	swap_a(t_env *env)
{
	t_stack	*tmp;

	if (n_nodes(&env->stack_a) > 0)
	{
		tmp = popnode_front(&env->stack_a);
		insert_node(&env->stack_a, tmp, 1);
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_env *env)
{
	t_stack	*tmp;

	if (n_nodes(&env->stack_b) > 0)
	{
		tmp = popnode_front(&env->stack_b);
		insert_node(&env->stack_b, tmp, 1);
		write(1, "sb\n", 3);
	}
}

void	swap_s(t_env *env)
{
	t_stack	*tmp;

	tmp = popnode_front(&env->stack_a);
	insert_node(&env->stack_a, tmp, 1);
	tmp = popnode_front(&env->stack_b);
	insert_node(&env->stack_b, tmp, 1);
	write(1, "ss\n", 3);
}
*/

void	swap_a(t_env *env)
{
	int	tmp;

	if (n_nodes(&env->stack_a) < 2)
		return ;
	tmp = (env->stack_a)->value;
	(env->stack_a)->value = (env->stack_a)->next->value;
	(env->stack_a)->next->value = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_env *env)
{
	int	tmp;

	if (n_nodes(&env->stack_b) < 2)
		return ;
	tmp = (env->stack_b)->value;
	(env->stack_b)->value = (env->stack_b)->next->value;
	(env->stack_b)->next->value = tmp;
	write(1, "sa\n", 3);
}

void	swap_s(t_env *env)
{
	int	tmp;

	if ((n_nodes(&env->stack_a) < 2) || (n_nodes(&env->stack_b) < 2))
		return ;
	tmp = (env->stack_a)->value;
	(env->stack_a)->value = (env->stack_a)->next->value;
	(env->stack_a)->next->value = tmp;
	tmp = (env->stack_b)->value;
	(env->stack_b)->value = (env->stack_b)->next->value;
	(env->stack_b)->next->value = tmp;
	write(1, "ss\n", 3);
}