/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 21:56:49 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/06 19:06:04 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_nodes(t_stack **head)
{
	t_stack	*cur;
	t_stack	*next;

	if (*head)
	{
		cur = *head;
		while (cur->next)
		{
			next = cur->next;
			free (cur);
			cur = next;
		}
	}
	//free (cur);
	//free (head);
}

void	clean_and_exit(char *s, t_env *env, int exit_code)
{
	clean_nodes(&env->stack_a);
	clean_nodes(&env->stack_b);
	free(env);
	msg_exit(s, exit_code);
}
