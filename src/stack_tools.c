/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 12:47:46 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/26 21:44:24 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

t_stack	*create_new_node(int val, int index)
{
	t_stack	*node;

	node = malloc(1 * sizeof(t_stack));
	node->value = val;
	node->index = index;
	node->next = NULL;
	return (node);
}

void	add_node_back(t_stack **head, t_stack *new_node)
{
	t_stack *tmp;

	tmp = (*head);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	add_node_front(t_stack **head, t_stack *new_node)
{
	t_stack	*tmp;

	tmp = *head;
	new_node->next = tmp;
	*head = new_node;
}

t_stack *pop_node_front(t_stack **head)
{
	t_stack *first;
	first = create_new_node((*head)->value, (*head)->index);
	first->next = NULL;
	(*head) = (*head)->next;
	return (first);
}

void	insert_node(t_stack **head, t_stack *new_node, int pos)
{
	t_stack	*edge_left;
	t_stack *mem;
	edge_left = *head;
	if (pos == 0)
	{
		new_node->next = edge_left;
		*head = new_node;
	}
	else
	{
		while ((pos > 1) && (edge_left->next))
		{
			edge_left = edge_left->next;
			pos--;
		}
		mem = edge_left->next;
		edge_left->next = new_node;
		new_node->next = mem;
	}
}

t_stack	*pop_node_back(t_stack **head)
{
	t_stack *tmp;
	t_stack	*popped;
	
	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	popped = tmp->next;
	tmp->next = NULL;
	return (popped);
}

int		n_nodes(t_stack **head)
{
	int	i;
	t_stack *tmp;

	i = 0;
	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	remove_node(t_stack **head, int pos)
{
	t_stack	*edge_left;
	t_stack *right;

	edge_left = *head;
	if (pos > n_nodes(head))
		pos = n_nodes(head);
	if (pos == 0)
		(*head) = (*head)->next;
	else
	{
		while ((pos > 1) && (edge_left->next))
		{
			edge_left = edge_left->next;
			pos--;
		}
		right = edge_left->next->next;
		edge_left->next = right;
	}
}

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

/*
ps_isordered()
Checks whether the elements in the linked list are numerically ordered,
from smallest to largest. If ordered, it returns 1. Else 0.
*/

int	ps_isordered(t_stack **head)
{
	int		previous;
	t_stack	*tmp;

	tmp = *head;
	previous = tmp->value;
	while (tmp)
	{
		if (tmp->value < previous)
			return (0);
		previous = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

/*
ps_hasduplicates()
Checks whether the linked list contains duplicate vals.
If so, it calls msg_exit() which exits the program.
*/

int	ps_hasduplicates(t_stack **head)
{
	int		match;
	t_stack	*i;
	t_stack	*j;

	i = *head;
	j = *head;
	while (i)
	{
		match = 0;
		while (j)
		{
			if (i->value == j->value)
				match++;
			if (match == 2)
				return (1);
			j = j->next;
		}
		i = i->next;
		j = *head;
	}
	return (0);
}

/*
ps_isvalid()
Checks whether user input is numeric. If not, exit the program.
It checks every character in the string for being either a digit, space, 
minus/plus sign character. If not, it prints an error statement and exits the
program with exit code 1.
*/

void	ps_isvalid(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != '+')
			msg_exit("Error", 2);
		if (s[i] == '-' && !ft_isdigit(s[i+1]))
			msg_exit("Error", 2);
		i++;
	}
}

/*
msg_exit()
Prints error statement to the standard error, followed by exiting the program.
*/

void	msg_exit(char *s, int exit_code)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(exit_code);
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

int		get_min_value(t_stack **head)
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

int		get_max_value(t_stack **head)
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