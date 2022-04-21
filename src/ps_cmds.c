/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_cmds.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/16 22:57:40 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/21 14:24:45 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_addlast(t_stack **lst, t_stack *new)
{
	t_stack	*final_element;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	final_element = ps_ll_getlast(*lst);
	final_element->next = new;
}

void	ps_push(t_stack **lst, t_stack *new)
{
	t_stack	*first_element;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	first_element = *lst;
	first_element->next = new;
}

/* SA */

void	ps_swap(t_stack *lst)
{
	int	val1;
	int	val2;
	t_stack	*tmp;

	if (ps_ll_len(lst) > 1)
	{
		tmp = lst;
		val1 = lst->value;
		val2 = lst->next->value;
		tmp->value = val2;
		tmp->next->value = val1;
		lst = tmp;
	}
}

void	ps_swap_sync(t_stack *lst1, t_stack *lst2)
{
	int	val1;
	int	val2;
	t_stack	*tmp;

	if (ps_ll_len(lst1) > 1)
	{
		tmp = lst1;
		val1 = lst1->value;
		val2 = lst1->next->value;
		tmp->value = val2;
		tmp->next->value = val1;
		lst1 = tmp;
	}
	if (ps_ll_len(lst2) > 1)
	{
		tmp = lst2;
		val1 = lst2->value;
		val2 = lst2->next->value;
		tmp->value = val2;
		tmp->next->value = val1;
		lst2 = tmp;
	}
}
