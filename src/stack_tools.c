/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 12:47:46 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/17 11:53:08 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			msg_exit("Error", 1);
		if (s[i] == '-' && !ft_isdigit(s[i+1]))
			msg_exit("Error", 1);
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
