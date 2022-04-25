/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_tools.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/16 22:47:04 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/25 22:42:06 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_getlast_node(t_stack *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	ps_nnodes(t_stack **lst)
{
	int	i;

	i = 0;
	while (*lst)
	{
		*lst = *lst->next;
		i++;
	}
	return (i);
}

void	print_list(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a)
		printf("List a NULL\n\n");
	else
	{
		printf("List a:\n");
		while (stack_a->next)
		{
			printf("%d=%d\n", stack_a->index, stack_a->value);
			stack_a = stack_a->next;
		}
		printf("%d=%d\n\n", stack_a->index, stack_a->value);
	}
	if (!stack_b)
		printf("List b NULL\n");
	else
	{
		printf("List b:\n");
		while (stack_b->next)
		{
			printf("%d=%d\n", stack_b->index, stack_b->value);
			stack_b = stack_b->next;
		}
		printf("%d=%d\n", stack_b->index, stack_b->value);
	}
	printf("\n---\n\n");
}