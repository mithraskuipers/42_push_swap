/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/28 19:29:07 by mikuiper      ########   odam.nl         */
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

t_stack	*parse_input(char **argv, t_env *env)
{
	int		i;
	int		j;
	//int		tmp_value;
	char	**splitted_args;
	i = 0;
	j = 0;
	(void)env;

	while (argv[i])
	{
		splitted_args = ft_split(argv[i], ' ');
		if (splitted_args == NULL)
			exit(1);
		while (splitted_args[j])
		{
			// check if input is numeric
			// check if duplicate
			j++;
		}
		i++;
		//add_node(env->stack_a, new_node(value));
	}
	return(0);
}

t_stack	*new_node(int value)
{
	t_stack	*tmp;

	tmp = malloc(1 * sizeof(t_stack));
	if (!tmp)
		exit(1);
	tmp->value = value;
	tmp->index = 0;
	tmp->next = NULL;
	tmp->previous = NULL;
	return (tmp);
}

/*
void	add_node(t_stack **stack, t_stack *node)
{
	
}
*/

void	stack_printer(t_stack **stack)
{
	while (*stack)
	{
		printf("value is: %d\n", (*stack)->value);
		*stack = (*stack)->next;
	}
}

int	main(int argc, char **argv)
{
	t_env	*env;

	env = ft_calloc(1, sizeof(t_stack));
	if (!env)
		exit(1);
	//env->stack_a = parse_input(argv, env);
	t_stack *tmp;
	tmp = new_node(10);
	//printf("%d", tmp->value);
	stack_printer(&tmp);
	return (0);
}
