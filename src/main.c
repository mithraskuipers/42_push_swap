/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/18 11:54:25 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
visualization of operations
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
*/

#include "push_swap.h"

void	remove_first_node(t_stack **head)
{
	t_stack	*new_head;

	new_head = (*head)->next;
	(*head) = new_head;
}

t_stack	*ret_last_node(t_stack **head)
{
	t_stack	*last_node;
	last_node = (*head);

	while (last_node)
		(last_node) = last_node->next;
	return (last_node);
}

void	lststack_add_back(t_stack **head, t_stack *new)
{
	while((*head)->next)
		(*head) = (*head)->next;
	(*head)->next = new;
}

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

void	ps_addlast(t_stack **head, t_stack *new)
{
	t_stack	*final_element;

	if (!(*head))
	{
		*head = new;
		return ;
	}
	final_element = ps_getlast_node(*head);
	final_element->next = new;
}

int	ps_nnodes(t_stack **lst)
{
	int	i;

	i = 0;
	while (*lst)
	{
		*lst = (*lst)->next;
		i++;
	}
	return (i);
}

t_stack	*ps_new_element(int index, int value)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (!(new_elem))
		return (NULL);
	new_elem->index = index;
	new_elem->value = value;
	new_elem->next = NULL;
	return (new_elem);
}

void	reset_index(t_stack **head)
{
	t_stack	*tmp;
	int	i;

	tmp = *head;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

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

void	simple_indexer(t_stack **head)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *head;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

int		get_min(t_stack **head)
{
	int		tmp_min;
	t_stack	*tmp;
	
	tmp = *head;
	tmp_min = tmp->value;
	while (tmp)
	{
		if (tmp_min > tmp->value)
			tmp_min = tmp->value;
		tmp = tmp->next;
	}
	return (tmp_min);
}

int		get_max(t_stack **head)
{
	int		tmp_max;
	t_stack	*tmp;
	
	tmp = *head;
	tmp_max = tmp->value;
	while (tmp)
	{
		if (tmp_max < tmp->value)
			tmp_max = tmp->value;
		tmp = tmp->next;
	}
	return (tmp_max);
}

int	get_idx_for_value(t_stack **head, int value)
{
	int		i;
	t_stack *tmp;
	
	i = 0;
	tmp = *head;
	while (tmp)
	{
		if (tmp->value == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return(-1);
}

/*
rotate_to_a(vars, 0);
push_b(vars);
rotate_to_a(vars, 1);
push_b(vars);
solver3(vars);
push_a(vars);
push_a(vars);

4 3 1 2 5
*/

/*
void	stack_index(t_stack *head)
{
	const int	stacklen = n_nodes(&head);
	t_stack	*tmp;
	t_stack	*smallest;
	int			i;

	i = 0;
	tmp = head;
	smallest = NULL;
	//simple_indexer(&head);
	while (i < stacklen)
	{
		//printf("%d\n", i);
		//i++;
		if (tmp->index == -1 && (smallest == NULL || tmp->value < smallest->value))
			smallest = tmp;
		if (tmp->next == head)
		{
			smallest->index = i;
			i++;
			smallest = NULL;
		}
		if (tmp->next)
			tmp = tmp->next;
		else
			return;
	}
}
*/


void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	int	index;

	index = get_idx_for_value(stack_a, get_min(stack_a));
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




void	sort_5(t_stack **stack_a, t_stack **stack_b, int go)
{
	int	index;

	index = get_idx_for_value(stack_a, get_min(stack_a));
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
	if (go == 1)
	{
		sort_5(stack_a, stack_b, 0);
		sort_3(stack_a);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);		
	}
}

/*
void	sort_3_rev(t_stack **head)
{
	t_stack	*start;
	t_stack	*middle;
	t_stack	*end;
	
	start = (*head);
	middle = (*head)->next;
	end = (*head)->next->next;
	if (middle->value > start->value && start->value > end->value)
		swap_a(head);
	else if (end->value > middle->value && middle->value > start->value)
	{
		swap_a(head);
		rrotate_a(head);
	}
	else if (middle->value > end->value && end->value > start->value)
		rotate_a(head);
	else if (start->value > end->value && end->value > middle->value)
	{
		swap_a(head);
		rotate_a(head);
	}
	else if (end->value > start->value && start->value > middle->value)
		rrotate_a(head);
}
*/

void	sort_6_helper(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	while (n_nodes(stack_a) != 3)
	{
		index = get_idx_for_value(stack_a, get_min(stack_a));
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

int	main(int argc, char **argv)
{
	t_env	*env;
	(void)argc;
	env = ft_calloc(1, sizeof(t_env));
	if (!env)
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
		sort_5(&env->stack_a, &env->stack_b, 1);
	else if (n_nodes(&env->stack_a) == 6)
		sort_6(&env->stack_a, &env->stack_b);
	print_forwards(&env->stack_a);
	return (0);
}






// Plaats de stacks in 1 enkele struct, genaamd env


/*
stack 4:
push laagste/hoogste weg naar b
solve dan stack a (3)
push dan terug

stack 5:
push 2 laagste/hoogste weg naar b
solve dan stack a (3)
push dan terug

stack 6:
zelfde idee??
*/



/*
4.
Vind de kleinste
Kijk in welke helft die index valt.
Als valt in 1e helft...
Als valt in 2e helft...
*/