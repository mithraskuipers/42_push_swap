/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 16:00:03 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/07 12:20:37 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_env *env)
{
	t_stack	*first_list;
	t_stack	*rotate_list;
	t_stack	*last_list;

	if (env->stack_a == NULL || env->stack_a->next == NULL)
		return ;
	rotate_list = env->stack_a;
	first_list = env->stack_a->next;
	last_list = env->stack_a;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	env->stack_a = first_list;
	write(1, "ra\n", 3);
}

void	rotate_b(t_env *env)
{
	t_stack	*first_list;
	t_stack	*rotate_list;
	t_stack	*last_list;

	if (env->stack_b == NULL || env->stack_b->next == NULL)
		return ;
	rotate_list = env->stack_b;
	first_list = env->stack_b->next;
	last_list = env->stack_b;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	env->stack_b = first_list;
	write(1, "rb\n", 3);
}

void	rotate_s(t_env *env)
{
	t_stack	*first_list;
	t_stack	*rotate_list;
	t_stack	*last_list;

	if (env->stack_a == NULL || env->stack_a->next == NULL || \
	env->stack_b == NULL || env->stack_b->next == NULL)
		return ;
	rotate_list = env->stack_a;
	first_list = env->stack_a->next;
	last_list = env->stack_a;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	env->stack_a = first_list;
	rotate_list = env->stack_b;
	first_list = env->stack_b->next;
	last_list = env->stack_b;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	env->stack_b = first_list;
	write(1, "rr\n", 3);
}
