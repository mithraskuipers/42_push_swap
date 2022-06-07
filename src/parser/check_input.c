/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/27 19:25:54 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/07 14:25:47 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	hasduplicates(t_stack **head)
{
	int		match;
	t_stack	*i;
	t_stack	*j;

	i = *head;
	j = *head;
	while (i)
	{
		match = 0;
		while (j)
		{
			if (i->value == j->value)
				match++;
			if (match == 2)
				return (1);
			j = j->next;
		}
		i = i->next;
		j = *head;
	}
	return (0);
}

int	isordered(t_stack **head)
{
	int		previous;
	t_stack	*tmp;

	tmp = *head;
	previous = tmp->value;
	while (tmp)
	{
		if (tmp->value < previous)
			return (0);
		previous = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

void	check_input(t_env *env)
{
	if (hasduplicates(&env->stack_a) == 1)
		clean_and_exit("Error", env, 1);
	if (isordered(&env->stack_a) == 1)
		clean_and_exit("", env, 0);
}
