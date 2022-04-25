/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_cmds.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/16 22:57:40 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/25 12:41:19 by mikuiper      ########   odam.nl         */
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
	final_element = ps_getlast_node(*lst);
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

