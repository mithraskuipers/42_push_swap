/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 21:56:49 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/31 22:59:33 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clean_stack(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free (*head);
		*head = tmp;
	}
	free (tmp);
}

void	clean_and_exit(char *s, t_env *env, int exit_code)
{
	if (&env->stack_a)
		clean_stack(&env->stack_a);
	if (&env->stack_b)
		clean_stack(&env->stack_b);
	if (env)
		free (env);
	msg_exit(s, exit_code);
}
