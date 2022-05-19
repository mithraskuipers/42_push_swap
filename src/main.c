/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/19 14:51:45 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
visualization of operations
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
*/

#include "push_swap.h"

void	sort_2(t_stack **head)
{
	swap_a(head);
}

void	sort_3(t_stack **head)
{
	t_stack	*start;
	t_stack	*middle;
	t_stack	*end;
	
	start = (*head);
	middle = (*head)->next;
	end = (*head)->next->next;
	if (middle->value < start->value && start->value < end->value)
		swap_a(head);
	else if (end->value < middle->value && middle->value < start->value)
	{
		swap_a(head);
		rrotate_a(head);
	}
	else if (middle->value < end->value && end->value < start->value)
		rotate_a(head);
	else if (start->value < end->value && end->value < middle->value)
	{
		swap_a(head);
		rotate_a(head);
	}
	else if (end->value < start->value && start->value < middle->value)
		rrotate_a(head);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	index = get_idx_for_value(stack_a, get_min_value(stack_a));
	if ((index + 1) == 4)
		rrotate_a(stack_a);
	else
	{
		while (index)
		{
			rotate_a(stack_a);
			index--;
		}
	}
	push_b(stack_a, stack_b);	
	sort_3(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_5_helper(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	index = get_idx_for_value(stack_a, get_min_value(stack_a));
	if ((index + 1) == 5)
		rrotate_a(stack_a);
	else
	{
		while (index)
		{
			rotate_a(stack_a);
			index--;
		}
	}
	push_b(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	sort_5_helper(stack_a, stack_b);
	sort_5_helper(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_6_helper(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	while (n_nodes(stack_a) != 3)
	{
		index = get_idx_for_value(stack_a, get_min_value(stack_a));
		if (index > (n_nodes(stack_a) / 2))
		{
			while (index <= (n_nodes(stack_a) - 1))
			{
				rrotate_a(stack_a);
				index++;
			}
		}
		else
		{
			while (index)
			{
				rotate_a(stack_a);
				index--;
			}
		}
		push_b(stack_a, stack_b);
	}
}

void	sort_6(t_stack **stack_a, t_stack **stack_b)
{
	sort_6_helper(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}








static t_stack	*get_next_min(t_stack **stack)
{
	int		i;
	int		has_min;
	t_stack	*min;
	t_stack	*current;

	min = NULL;
	if (*stack)
	{
		i = 0;
		has_min = 0;
		current = *stack;
		while (i < n_nodes(stack))
		{
			if ((current->index == -1) && (!has_min || current->value < min->value))
			{
				has_min = 1;
				min = current;
			}
			i++;
			current = current->next;
		}
	}
	return (min);
}

void				index_stack(t_stack **stack)
{
	size_t	index;
	t_stack	*current;

	index = 0;
	while ((current = get_next_min(stack)))
		current->index = index++;
}







int	main(int argc, char **argv)
{
	t_env	*env;
	(void)argc;
	env = ft_calloc(1, sizeof(t_env));
	if (!env || argc < 2)
		exit(1);
	parse_input(argv, &env->stack_a);
	if (ps_isordered(&env->stack_a))
		msg_exit("Error. Input is already ordered", 1);
	if (ps_hasduplicates(&env->stack_a))
		msg_exit("Error. Input contains duplicates.", 1);

	if (n_nodes(&env->stack_a) == 2)
		sort_2(&env->stack_a);
	else if (n_nodes(&env->stack_a) == 3)
		sort_3(&env->stack_a);
	else if (n_nodes(&env->stack_a) == 4)
		sort_4(&env->stack_a, &env->stack_b);
	else if (n_nodes(&env->stack_a) == 5)
		sort_5(&env->stack_a, &env->stack_b);
	else if (n_nodes(&env->stack_a) == 6)
		sort_6(&env->stack_a, &env->stack_b);

	//index_stack(&env->stack_a);
	print_forwards(&env->stack_a);
	//system("leaks push_swap");
	return (0);
}