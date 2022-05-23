/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/23 14:28:08 by mikuiper      ########   odam.nl         */
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
	t_stack	*tmp_min;
	int		min;
	t_stack	*tmp;
	
	tmp = *head;
	tmp_min = tmp;
	min = tmp_min->value;
	while (tmp)
	{
		if ((min > tmp->value) && (tmp->index == -1))
		{
			min = tmp->value;
			tmp_min = tmp;
		}
		tmp = tmp->next;
	}
	return (tmp_min);
}

/*
void	indexer(t_stack **head)
{
	int		index;

	index = 0;

	t_stack	*tmp;
	tmp = *head;
	//printf("%d\n", n_nodes(head));
	while (index < n_nodes(head))
	{
		get_next_unindex_min(head)->index = index;
		head = &(*head)->next;
		printf("Current value index: %d\n", index);
		index++;
	}
}
*/

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

	//indexer(&env->stack_a);
	/*
	get_next_unindex_min(&env->stack_a)->index = 0;
	get_next_unindex_min(&env->stack_a)->index = 1;
	get_next_unindex_min(&env->stack_a)->index = 2;
	get_next_unindex_min(&env->stack_a)->index = 3;
	get_next_unindex_min(&env->stack_a)->index = 4;
	get_next_unindex_min(&env->stack_a)->index = 5;
	get_next_unindex_min(&env->stack_a)->index = 6;
	get_next_unindex_min(&env->stack_a)->index = 7;
	get_next_unindex_min(&env->stack_a)->index = 8;
	*/

	int a = 1;
	while (a < n_nodes(&env->stack_a))
	{
		a++;
		get_next_unindex_min(&env->stack_a)->index = a;
	}


	print_forwards(&env->stack_a);
	//system("leaks push_swap");
	return (0);
}