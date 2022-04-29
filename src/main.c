/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/29 15:25:14 by mikuiper      ########   odam.nl         */
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

void	add_node(t_stack **stack, t_stack *new_node)
{
	(*stack)->next = new_node;
}

t_stack	*find_last_node(t_stack **head)
{
	t_stack	*last_node;
	last_node = (*head);

	while (last_node)
		(last_node) = last_node->next;
	printf("\nreached last node!\n");
	return (last_node);
}

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(1 * sizeof(t_stack));
	node->value = value;
	node->index = 0;
	node->next = NULL;
	node->previous = NULL;
	return (node);
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
			//add_node(&env->stack_a, new_node(ft_atoi(splitted_args[j])));
			//t_stack	*tmp;
			//tmp = new_node(splitted_args[j]);
			//printf("%d", tmp->value);
			//printf("%s", splitted_args[j]);
			//printf("%d", ft_atoi(splitted_args[j]));
			j++;
		}
		i++;
	}
	return (env->stack_a);
}

void	stack_printer(t_stack **stack)
{
	while (*stack)
	{
		printf("index [%d] value %d \n", (*stack)->index, (*stack)->value);
		(*stack) = (*stack)->next;
	}
}

t_stack	*pop_node(t_stack **head)
{
	t_stack	*new_head;
	t_stack	*popped_head;

	popped_head = (*head);
	popped_head->next = NULL;
	popped_head->previous = NULL;
	new_head = (*head)->next;
	(*head) = new_head;
	return (popped_head);
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
	t_stack *node1;
	head = new_node(10);
	node1 = new_node(20);
	add_node(&head, node1);
	//t_stack *test;
	//test = pop_node(&head);
	
	t_stack *last_node;
	last_node = find_last_node(&head);
	stack_printer(&last_node);
	return (0);
}
