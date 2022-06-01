/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/27 19:25:54 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/01 23:10:11 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ps_hasduplicates()
Checks whether the linked list contains duplicate vals.
If so, it calls msg_exit() which exits the program.
*/

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

/*
isordered()
Checks whether the elements in the linked list are numerically ordered,
from smallest to largest. If ordered, it returns 1. Else 0. Is also used in
radix sort.
*/

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
		msg_exit("Error", 2);
	if (isordered(&env->stack_a) == 1)
		msg_exit("", 1);
}
