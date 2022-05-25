/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/25 14:51:30 by mikuiper      ########   odam.nl         */
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

t_stack	*get_next_unindex_min(t_stack **head)
{
	int		min_value;
	t_stack	*tmp_node;
	t_stack	*minimum_node;
	
	tmp_node = *head;
	minimum_node = tmp_node;
	min_value = INTMAX;
	while (tmp_node)
	{
		if ((min_value > tmp_node->value) && (tmp_node->index == -1))
		{
			min_value = tmp_node->value;
			minimum_node = tmp_node;
		}
		tmp_node = tmp_node->next;
	}
	return (minimum_node);
}


void	indexer(t_stack **head)
{
	int a = 0;
	while (a < n_nodes(head))
	{
		get_next_unindex_min(head)->index = a;
		a++;
	}
}

/*
count_bits() calls get_max_value() to find the largest value
in the linked list, and then uses bitwise shifting using the
right shift operator to count the number of bits required
to express that value in binary.
*/

int	count_bits(t_stack **head)
{
	int		max_bits;
	int		largest_val;
	t_stack	*tmp;

	max_bits = 0;
	largest_val = get_max_value(head);
	tmp = *head;
	while ((largest_val >> max_bits) > 0)
		max_bits++;
	return (max_bits);
}

/*

*/

void	radix(t_env *env)
{
	int		i;
	int		j;
	t_stack	*head_a;

	i = 0;
	while (i < count_bits(&env->stack_a))
	{
		j = 0;
		while (j < n_nodes(&env->stack_a))
		{
			head_a = *&env->stack_a;
			if (((head_a->index >> i) & 1) == 1)
				rotate_a(&env->stack_a);
			else
				push_b(&env->stack_a, &env->stack_b);
			j++;
		}
		while (n_nodes(&env->stack_b) != 0)
			push_a(&env->stack_a, &env->stack_b);
		i++;
	}
}

void	sort_stack(t_env *env)
{
	int	stack_len;

	stack_len = n_nodes(&env->stack_a);
	if (stack_len > 6)
	{
		indexer(&env->stack_a);
		radix(env);
	}
	else if ((stack_len) == 2)
		sort_2(&env->stack_a);
	else if ((stack_len) == 3)
		sort_3(&env->stack_a);
	else if ((stack_len) == 4)
		sort_4(&env->stack_a, &env->stack_b);
	else if ((stack_len) == 5)
		sort_5(&env->stack_a, &env->stack_b);
	else if ((stack_len) == 6)
		sort_6(&env->stack_a, &env->stack_b);
}

void	check_input(t_env *env)
{
	if (ps_hasduplicates(&env->stack_a))
		msg_exit("Error. Input contains duplicates.", 1);
	if (ps_isordered(&env->stack_a))
		msg_exit("Error. Input is already ordered", 1);
}

int	main(int argc, char **argv)
{
	t_env	*env;
	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		msg_exit("Could not allocate memory for environment struct.", 1);
	else if (argc < 2)
		msg_exit("Please enter a list of numbers.", 1);
	parse_input(argv, env);
	check_input(env);
	//sort_stack(env);
	//swap_a(&env->stack_a); // leak!
	push_b(&env->stack_a, &env->stack_b); // leak!
	//swap_b(&env->stack_b); // ???
	print_forwards(&env->stack_a);
	system("leaks push_swap");
	return (0);
}
