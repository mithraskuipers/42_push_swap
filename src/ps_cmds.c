/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_cmds.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/16 22:57:40 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/19 14:16:02 by mikuiper      ########   odam.nl         */
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

void	ps_swap_a(t_stack **lst)
{
	int tmp;
	tmp = lst->next;
	ft_putnbr_fd(tmp.value, 2);
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