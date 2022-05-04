/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/04 15:06:14 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
visualization of operations
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
*/

#include "push_swap.h"

typedef struct	s_stack
{
	int	value;
	int	index;
	struct s_stack *next;
	struct s_stack *previous;
}				t_stack;

typedef struct	s_env
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_env;

void	remove_first_node(t_stack **head)
{
	t_stack	*new_head;

	new_head = (*head)->next;
	(*head) = new_head;
}

void	add_node_back(t_stack **head, t_stack *new_node)
{
	while ((*head)->next)
		*head = (*head)->next;
	(*head)->next = new_node;
}

void	add_node_front(t_stack **head, t_stack *new_node)
{
	t_stack	*tmp;

	tmp = *head;
	new_node->next = tmp;
	*head = new_node;
}

t_stack	*ret_last_node(t_stack **head)
{
	t_stack	*last_node;
	last_node = (*head);

	while (last_node)
		(last_node) = last_node->next;
	return (last_node);
}

t_stack	*create_new_node(int value, int index)
{
	t_stack	*node;

	node = malloc(1 * sizeof(t_stack));
	node->value = value;
	node->index = index;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

t_stack *pop_node_front(t_stack **head)
{
	t_stack *first;
	first = create_new_node((*head)->value, (*head)->index);
	first->next = NULL;
	(*head) = (*head)->next;
	return (first);
}

void	print_forwards(t_stack **head)
{
	while (*head)
	{
		printf("index [%d] value %d \n", (*head)->index, (*head)->value);
		(*head) = (*head)->next;
	}
}

void	print_backwards(t_stack **head)
{
	t_stack *tmp;
	while ((*head)->next)
	{
		//printf("index [%d] value %d \n", (*head)->index, (*head)->value);
		(*head) = (*head)->next;
	}
	tmp = (*head);
	while (tmp->previous)
	{
		tmp = tmp->previous;
		printf("index [%d] value %d \n", tmp->index, tmp->value);

	}
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

void	swap(t_stack **head)
{
	t_stack *tmp;
	
	tmp = pop_node_front(head);
	insert_node(head, tmp, 1);
}

void	swap_s(t_stack **head1, t_stack **head2)
{
	t_stack *tmp;
	
	tmp = pop_node_front(head1);
	insert_node(head1, tmp, 1);
	tmp = pop_node_front(head2);
	insert_node(head2, tmp, 1);
}


void	rotate(t_stack **head)
{
	t_stack *tmp;

	tmp = pop_node_front(head);
	add_node_back(head, tmp);
}

void	rotate_s(t_stack **head1, t_stack **head2)
{
	t_stack *tmp;

	tmp = pop_node_front(head1);
	add_node_back(head1, tmp);

	tmp = pop_node_front(head2);
	add_node_back(head2, tmp);
}

int		n_nodes(t_stack **head)
{
	int	i;
	t_stack *tmp;

	i = 0;
	tmp = *head;
	while (tmp->next)
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

void	lststack_add_back(t_stack **head, t_stack *new)
{
	while((*head)->next)
	{
		(*head) = (*head)->next;
	}
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

int	mk_iswhitespace(int c)
{
	if ((c == ' ') || (c == '\t') || (c == '\v') || (c == '\r') || (c == '\n') \
	|| (c == '\f'))
		return (1);
	return (0);
}

int	mk_atoi(char *s, int *nbr)
{
	int	i;
	int	sign;
	int value;

	(void)nbr;
	i = 0;
	while (mk_iswhitespace(s[i]))
		i++;
	value = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		value = (value * 10) + (s[i] - '0');
		i++;
	}
	*nbr = value * sign;
	return (0);
}

void	parse_input(char **argv, t_stack **head)
{
	int		i;
	int		j;
	char	**splitted_args;
	i = 0;
	j = 0;
	i = 1;

	while (argv[i])
	{
		splitted_args = ft_split(argv[i], ' ');
		if (splitted_args == NULL)
			exit(1);
		j = 0;
		while (splitted_args[j])
		{
			// TODO check if input is numeric
			// TODO check if duplicate
			//t_stack *tmp;
			//tmp = create_new_node(ft_atoi(splitted_args[j]), 1);
			//add_node_back(&head, tmp);
			//printf("%d", tmp->value);
			//printf("%d", ft_atoi(splitted_args[j]));
			ps_addlast(head, ps_new_element(ft_atoi(splitted_args[j]), -1));
			j++;
		}
		i++;
	}
	print_forwards(head);
	return ;
}

int	main(int argc, char **argv)
{
	t_env	*env;
	(void)argc;
	env = ft_calloc(1, sizeof(t_stack));
	if (!env)
		exit(1);
	
	t_stack **new;
	new = ft_calloc(1, sizeof(t_stack));
	//new = NULL;
	//new = create_new_node(1,0);
	parse_input(argv, new);
	print_forwards(new);

	int tmp;
	mk_atoi("123", &tmp);
	printf("%d", tmp);

	return (0);
} 

/*
TODO
pointers to previous
reverse rotate
*/
