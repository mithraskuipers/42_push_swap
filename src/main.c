/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/02 14:29:54 by mikuiper      ########   odam.nl         */
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
	t_stack	*tmp;
	t_stack *prev;

	tmp = *head;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->previous = prev;
	tmp->next = new_node;
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

t_stack	*create_new_node(int value)
{
	t_stack	*node;

	node = malloc(1 * sizeof(t_stack));
	node->value = value;
	node->index = 0;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

t_stack *pop_node_front(t_stack **head)
{
	t_stack *first;
	first = create_new_node((*head)->value);
	first->next = NULL;
	(*head) = (*head)->next;
	return (first);
}

t_stack	*parse_input(char **argv, t_env *env)
{
	int		i;
	int		j;
	char	**splitted_args;
	i = 0;
	j = 0;
	(void)env;
	i = 1;
	while (argv[i])
	{
		splitted_args = ft_split(argv[i], ' ');
		if (splitted_args == NULL)
			exit(1);
		j = 0;
		while (splitted_args[j])
		{
			// check if input is numeric
			// check if duplicate
			//add_node_back(&env->stack_a, create_new_node(ft_atoi(splitted_args[j])));
			//t_stack	*tmp;
			//tmp = create_new_node(splitted_args[j]);
			//printf("%d", tmp->value);
			//printf("%s", splitted_args[j]);
			//printf("%d", ft_atoi(splitted_args[j]));
			j++;
		}
		i++;
	}
	return (env->stack_a);
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

// werkt, maar protect zodat je niet out of bounds
// als pos groter dan len, pak dan len
void	remove_node(t_stack **head, int pos)
{
	t_stack	*edge_left;
	t_stack *right;

	edge_left = *head;
	while ((pos > 1) && (edge_left->next))
	{
		edge_left = edge_left->next;
		pos--;
	}
	right = edge_left->next->next;
	edge_left->next = right;
}

int	main(int argc, char **argv)
{
	t_env	*env;
	(void)argc;
	env = ft_calloc(1, sizeof(t_stack));
	if (!env)
		exit(1);
	parse_input(argv, env);

	t_stack	*head1;
	head1 = create_new_node(10);
	add_node_back(&head1, create_new_node(20));
	add_node_back(&head1, create_new_node(30));
	add_node_back(&head1, create_new_node(40));
	add_node_back(&head1, create_new_node(50));

	t_stack	*head2;
	head2 = create_new_node(11);
	add_node_back(&head2, create_new_node(22));
	add_node_back(&head2, create_new_node(33));
	add_node_back(&head2, create_new_node(44));
	add_node_back(&head2, create_new_node(55));
	
	//t_stack *tmp;
	//remove_first_node(&head);
	//insert_node(&head, create_new_node(99), 0);
	//swap(&head);
	//t_stack *tmp;

	//tmp = pop_node_front(&head);
	//printf("\n");
	//print_forwards(&tmp);
	//swap(&head);
	//remove_last_node(&head);
	//remove_node(&head, 4);

	swap_s(&head1, &head2);
	rotate_s(&head1, &head2);

	print_forwards(&head1);
	printf("\n");
	print_forwards(&head2);

	print_backwards(&head2);
	//printf("\n\n");
	//print_forwards(&tmp);
	return (0);
} 


/*
TODO
pointers to previous
reverse rotate
*/

