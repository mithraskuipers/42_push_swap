/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/28 23:38:42 by mikuiper      ########   odam.nl         */
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
		printf("%d", (*stack)->value);
		(*stack) = (*stack)->next;
	}
}


int	main(int argc, char **argv)
{
	t_env	*env;
	//t_stack	*stack_a;

	(void)argc;
	env = ft_calloc(1, sizeof(t_stack));
	if (!env)
		exit(1);
	parse_input(argv, env);

	t_stack *tmp;
	t_stack *tmp2;
	tmp = new_node(10);
	tmp2 = new_node(20);
	//(void)tmp2;
	//printf("%d", tmp->value);
	//printf("%d", tmp2->value);
	add_node(&tmp, tmp2);
	stack_printer(&tmp);
	return (0);
}
