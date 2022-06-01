/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 21:56:49 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/01 23:15:37 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	clean_stack(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		*head = tmp;
		free (tmp);
	}
}
*/

static void clean_nodes(t_stack **head)
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
}

void	clean_and_exit(char *s, t_env *env, int exit_code)
{
	clean_nodes(&env->stack_a);
	clean_nodes(&env->stack_b);
	free(env);
	msg_exit(s, exit_code);
}
