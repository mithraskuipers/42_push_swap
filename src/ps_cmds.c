/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_cmds.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/16 22:57:40 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/20 12:36:31 by mikuiper      ########   odam.nl         */
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

/* SA */

void	ps_swap_a(t_stack *lst)
{
	// TODO Do nothing if there is only one or no elements.
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

/*/
previous = tmp->value;
while (tmp)
{
	if (tmp->value < previous)
		return (0);
	previous = tmp->value;
	tmp = tmp->next;
}
*/