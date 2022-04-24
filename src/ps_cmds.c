/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_cmds.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/16 22:57:40 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/24 22:22:06 by mikuiper      ########   odam.nl         */
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

/* SA */

void	ps_swap_sa(t_stack *lst)
{
	int	val1;
	int	val2;
	t_stack	*tmp;

	if (ps_nnodes(lst) > 1)
	{
		tmp = lst;
		val1 = lst->value;
		val2 = lst->next->value;
		tmp->value = val2;
		tmp->next->value = val1;
		lst = tmp;
	}
	ft_putstr_fd("sa\n", 1);
}

void	ps_swap_sb(t_stack *lst)
{
	int	val1;
	int	val2;
	t_stack	*tmp;

	if (ps_nnodes(lst) > 1)
	{
		tmp = lst;
		val1 = lst->value;
		val2 = lst->next->value;
		tmp->value = val2;
		tmp->next->value = val1;
		lst = tmp;
	}
	ft_putstr_fd("sb\n", 1);
}


void	ps_swap_ss(t_stack *lst1, t_stack *lst2)
{
	if (ps_nnodes(lst1) > 1)
	{
		ps_swap_a(lst1);
	}
	if (ps_nnodes(lst2) > 1)
	{
		ps_swap_b(lst2);
	}
	ft_putstr_fd("ss\n", 1);
}
