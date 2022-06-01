/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_node.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 10:46:37 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/01 20:29:41 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_idx_for_val(t_stack **head, int value)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *head;
	while (tmp)
	{
		if (tmp->value == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

t_stack	*get_last(t_stack **head)
{
	t_stack *tmp;

	tmp = *head;
	while (tmp)
	{
		if (!(tmp->next))
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

int	get_min_val(t_stack **head)
{
	int		tmp_min;
	t_stack	*tmp;

	tmp = *head;
	tmp_min = tmp->value;
	while (tmp)
	{
		if (tmp_min > tmp->value)
			tmp_min = tmp->value;
		tmp = tmp->next;
	}
	return (tmp_min);
}
