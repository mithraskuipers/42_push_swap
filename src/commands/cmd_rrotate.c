/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rrotate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 18:09:30 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/07 14:19:28 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_env *env)
{
	t_stack	*head;
	t_stack	*new_start;
	t_stack	*new_end;

	head = (env->stack_a);
	new_end = (env->stack_a);
	new_start = (env->stack_a);
	if (n_nodes(&(env->stack_a)) < 2)
		return ;
	while (new_start->next != NULL)
	{
		new_start = new_start->next;
		if (new_start->next != NULL)
			new_end = new_end->next;
	}
	new_start->next = head;
	new_end->next = NULL;
	(env->stack_a) = new_start;
	write(1, "rra\n", 4);
}

void	rrotate_b(t_env *env)
{
	t_stack	*head;
	t_stack	*new_start;
	t_stack	*new_end;

	head = (env->stack_b);
	new_end = (env->stack_b);
	new_start = (env->stack_b);
	if (n_nodes(&(env->stack_b)) < 2)
		return ;
	while (new_start->next != NULL)
	{
		new_start = new_start->next;
		if (new_start->next != NULL)
			new_end = new_end->next;
	}
	new_start->next = head;
	new_end->next = NULL;
	(env->stack_b) = new_start;
	write(1, "rrb\n", 4);
}

void	rrotate_sa(t_env *env)
{
	t_stack	*head;
	t_stack	*new_start;
	t_stack	*new_end;

	head = (env->stack_a);
	new_end = (env->stack_a);
	new_start = (env->stack_a);
	if (n_nodes(&(env->stack_a)) < 2)
		return ;
	while (new_start->next != NULL)
	{
		new_start = new_start->next;
		if (new_start->next != NULL)
			new_end = new_end->next;
	}
	new_start->next = head;
	new_end->next = NULL;
	(env->stack_a) = new_start;
}

void	rrotate_sb(t_env *env)
{
	t_stack	*head;
	t_stack	*new_start;
	t_stack	*new_end;

	head = (env->stack_b);
	new_end = (env->stack_b);
	new_start = (env->stack_b);
	if (n_nodes(&(env->stack_b)) < 2)
		return ;
	while (new_start->next != NULL)
	{
		new_start = new_start->next;
		if (new_start->next != NULL)
			new_end = new_end->next;
	}
	new_start->next = head;
	new_end->next = NULL;
	(env->stack_b) = new_start;
}

void	rrotate_s(t_env *env)
{
	if ((n_nodes(&(env->stack_a)) < 2) || (n_nodes(&(env->stack_b)) < 2))
		return ;
	rrotate_sa(env);
	rrotate_sb(env);
	write(1, "rrr\n", 4);
}
