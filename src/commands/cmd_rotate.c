/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 16:00:03 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/07 14:18:27 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_env *env)
{
	t_stack	*old_head;
	t_stack	*new_head;
	t_stack	*tail;

	if ((n_nodes(&(env->stack_a)) < 2))
		return ;
	old_head = (env->stack_a);
	new_head = (env->stack_a)->next;
	tail = (env->stack_a);
	while (tail->next != NULL)
		tail = tail->next;
	old_head->next = NULL;
	tail->next = old_head;
	(env->stack_a) = new_head;
	write(1, "ra\n", 3);
}

void	rotate_b(t_env *env)
{
	t_stack	*old_head;
	t_stack	*new_head;
	t_stack	*tail;

	if ((n_nodes(&(env->stack_b)) < 2))
		return ;
	old_head = (env->stack_b);
	new_head = (env->stack_b)->next;
	tail = (env->stack_b);
	while (tail->next != NULL)
		tail = tail->next;
	old_head->next = NULL;
	tail->next = old_head;
	(env->stack_b) = new_head;
	write(1, "rb\n", 3);
}

void	rotate_s(t_env *env)
{
	t_stack	*old_head;
	t_stack	*new_head;
	t_stack	*tail;

	if ((n_nodes(&(env->stack_a)) < 2) || (n_nodes(&(env->stack_b)) < 2))
		return ;
	old_head = (env->stack_a);
	new_head = (env->stack_a)->next;
	tail = (env->stack_a);
	while (tail->next != NULL)
		tail = tail->next;
	old_head->next = NULL;
	tail->next = old_head;
	(env->stack_a) = new_head;
	old_head = (env->stack_b);
	new_head = (env->stack_b)->next;
	tail = (env->stack_b);
	while (tail->next != NULL)
		tail = tail->next;
	old_head->next = NULL;
	tail->next = old_head;
	(env->stack_b) = new_head;
	write(1, "rr\n", 3);
}
