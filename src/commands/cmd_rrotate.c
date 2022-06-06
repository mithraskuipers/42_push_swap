/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rrotate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 18:09:30 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/06 20:00:24 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	rrotate_a(t_env *env)
{
	t_stack	*tmp;

	tmp = popnode_end(&env->stack_a);
	addnode_front(&env->stack_a, tmp);
	write(1, "rra\n", 4);
}

void	rrotate_b(t_env *env)
{
	t_stack	*tmp;

	tmp = popnode_end(&env->stack_b);
	addnode_front(&env->stack_b, tmp);
	write(1, "rrb\n", 4);
}

void	rrotate_s(t_env *env)
{
	t_stack	*tmp;

	tmp = popnode_end(&env->stack_a);
	addnode_front(&env->stack_a, tmp);
	tmp = popnode_end(&env->stack_b);
	addnode_front(&env->stack_b, tmp);
	write(1, "rrr\n", 4);
}
*/

void	rrotate_a(t_env *env)
{
	t_stack	*front;
	t_stack	*back;
	t_stack	*head;

	head = env->stack_a;
	back = env->stack_a;
	front = env->stack_a;
	if (env->stack_a == NULL)
		return ;
	while (front->next != NULL)
	{
		front = front->next;
		if (front->next != NULL)
			back = back->next;
	}
	if (front->next == NULL)
	{
		front->next = head;
		back->next = NULL;
	}
	env->stack_a = front;
	write(1, "rra\n", 4);
}

void	rrotate_b(t_env *env)
{
	t_stack	*front;
	t_stack	*back;
	t_stack	*head;

	head = env->stack_b;
	back = env->stack_b;
	front = env->stack_b;
	if (env->stack_b == NULL)
		return ;
	while (front->next != NULL)
	{
		front = front->next;
		if (front->next != NULL)
			back = back->next;
	}
	if (front->next == NULL)
	{
		front->next = head;
		back->next = NULL;
	}
	env->stack_b = front;
	write(1, "rrb\n", 4);
}

void	rrotate_s(t_env *env)
{
	t_stack	*front;
	t_stack	*back;
	t_stack	*head;

	head = env->stack_a;
	back = env->stack_a;
	front = env->stack_a;
	if (env->stack_a == NULL)
		return ;
	while (front->next != NULL)
	{
		front = front->next;
		if (front->next != NULL)
			back = back->next;
	}
	if (front->next == NULL)
	{
		front->next = head;
		back->next = NULL;
	}
	env->stack_a = front;
	// scheiding hier tussen rra en rrb
	head = env->stack_b;
	back = env->stack_b;
	front = env->stack_b;
	if (env->stack_b == NULL)
		return ;
	while (front->next != NULL)
	{
		front = front->next;
		if (front->next != NULL)
			back = back->next;
	}
	if (front->next == NULL)
	{
		front->next = head;
		back->next = NULL;
	}
	env->stack_b = front;
	write(1, "rrr\n", 4);
}
