/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_cmds.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/16 22:57:40 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/17 14:46:50 by mikuiper      ########   odam.nl         */
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
	final_element = ps_list_findlast(*lst);
	final_element->next = new;
}
