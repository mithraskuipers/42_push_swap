/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/01 21:26:33 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct	s_stack
{
	int	value;
	int	index;
	struct s_stack *next;
	struct s_stack_*previous;
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

void	add_node_back(t_stack **head, t_stack *create_new_node)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_new_node;
}

void	add_node_front(t_stack **head, t_stack *create_new_node)
{
	t_stack	*tmp;

	tmp = *head;
	create_new_node->next = tmp;
	*head = create_new_node;
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

void	stack_printer(t_stack **head)
{
	while (*head)
	{
		printf("index [%d] value %d \n", (*head)->index, (*head)->value);
		(*head) = (*head)->next;
	}
}

void	insert_node(t_stack **head, t_stack *create_new_node, int pos)
{
	t_stack	*edge_left;
	t_stack *mem;
	edge_left = *head;
	if (pos == 0)
	{
		create_new_node->next = edge_left;
		*head = create_new_node;
	}
	else
	{
		while ((pos > 1) && (edge_left->next))
		{
			edge_left = edge_left->next;
			pos--;
		}
		mem = edge_left->next;
		edge_left->next = create_new_node;
		create_new_node->next = mem;
	}
}

void	swap_a(t_stack **head)
{
	//t_stack	*tmp;
	
	//tmp = *head;
	*head = (*head)->next;
	//add_node_front(head, tmp);
	
}

int	main(int argc, char **argv)
{
	t_env	*env;
	(void)argc;
	env = ft_calloc(1, sizeof(t_stack));
	if (!env)
		exit(1);
	parse_input(argv, env);

	t_stack	*head;
	head = create_new_node(10);
	add_node_back(&head, create_new_node(20));
	add_node_back(&head, create_new_node(30));
	add_node_back(&head, create_new_node(40));
	add_node_back(&head, create_new_node(50));


	//t_stack *tmp;
	//remove_first_node(&head);
	//insert_node(&head, create_new_node(99), 0);
	//swap_a(&head);
	t_stack *tmp;

	tmp = pop_node_front(&head);
	stack_printer(&head);
	printf("\n");
	stack_printer(&tmp);
	//printf("\n\n");
	//stack_printer(&tmp);
	return (0);
} 


