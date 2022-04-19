/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_done.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/16 21:47:50 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/19 11:55:56 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ps_isordered()
Checks whether the elements in the linked list are numerically ordered,
from smallest to largest. If ordered, it returns 1. Else 0.
*/

int	ps_isordered(t_stack *stack)
{
	int		previous;
	t_stack	*tmp;

	tmp = stack;
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
