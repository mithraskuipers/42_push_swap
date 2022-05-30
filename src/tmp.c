/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 23:19:50 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/30 23:20:12 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_forwards(t_stack **head)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *head;
	while (tmp)
	{
		printf("node %d: %d [%d]\n", i, (tmp)->value, (tmp)->index);
		(tmp) = (tmp)->next;
		i++;
	}
}
