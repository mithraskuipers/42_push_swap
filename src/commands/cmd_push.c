/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_push.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 19:37:07 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/07 14:20:24 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_env *env)
{
	t_stack	*tmp;

	if (n_nodes(&(env->stack_b)) == 0)
		return ;
	tmp = (env->stack_b);
	(env->stack_b) = (env->stack_b)->next;
	tmp->next = (env->stack_a);
	(env->stack_a) = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_env *env)
{
	t_stack	*tmp;

	if (n_nodes(&(env->stack_a)) == 0)
		return ;
	tmp = (env->stack_a);
	(env->stack_a) = (env->stack_a)->next;
	tmp->next = (env->stack_b);
	(env->stack_b) = tmp;
	write(1, "pb\n", 3);
}
