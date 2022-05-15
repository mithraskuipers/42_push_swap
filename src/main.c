/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/15 12:07:16 by rkieboom      ########   odam.nl         */
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

t_stack	*ps_new_element(int index, int val)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (!(new_elem))
		return (NULL);
	new_elem->index = index;
	new_elem->val = val;
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
	if (middle->val < start->val && start->val < end->val)
		swap_a(head);
	else if (end->val < middle->val && middle->val < start->val)
	{
		swap_a(head);
		rrotate_a(head);
	}
	else if (middle->val < end->val && end->val < start->val)
		rotate_a(head);
	else if (start->val < end->val && end->val < middle->val)
	{
		swap_a(head);
		rotate_a(head);
	}
	else if (end->val < start->val && start->val < middle->val)
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
	tmp_min = tmp->val;
	while (tmp)
	{
		if (tmp_min > tmp->val)
			tmp_min = tmp->val;
		tmp = tmp->next;
	}
	return (tmp_min);
}

int		get_max(t_stack **head)
{
	int		tmp_max;
	t_stack	*tmp;
	
	tmp = *head;
	tmp_max = tmp->val;
	while (tmp)
	{
		if (tmp_max < tmp->val)
			tmp_max = tmp->val;
		tmp = tmp->next;
	}
	return (tmp_max);
}

int	get_idx_for_val(t_stack **head, int value)
{
	int		i;
	t_stack *tmp;
	
	i = 0;
	tmp = *head;
	while (tmp)
	{
		if (tmp->val == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return(-1);
}

void	sort_4(t_stack **stack_a)
{
	(void)stack_a;
	printf("Hey\n");
}

int	main(int argc, char **argv)
{
	t_env	*env;
	(void)argc;
	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		exit(1);
	parse_input(argv, &env->stack_a);
	//reset_index(new);
	//insertionSort(new);
	if (ps_isordered(&env->stack_a))
		msg_exit("Error. Input is already ordered", 1);
	if (ps_hasduplicates(&env->stack_a))
		msg_exit("Error. Input contains duplicates.", 1);
	if (n_nodes(&env->stack_a) == 2)
		sort_2(&env->stack_a);

	else if (n_nodes(&env->stack_a) == 3)
		sort_3(&env->stack_a);

	simple_indexer(&env->stack_a);
	sort_4(&env->stack_a);
	print_forwards(&env->stack_a);

	//printf("%d", get_idx_for_val(&env->stack_a, 44));
	//printf("%d", INT_MAX);
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