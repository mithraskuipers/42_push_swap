/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/25 23:26:57 by mikuiper      ########   odam.nl         */
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

t_stack_a	*parse_input(char **argv, t_env *env)
{
	int		i;
	int		j;
	int		tmp_value;
	char	**splitted_args;

	while (argv[i])
	{
		splitted_args = ft_split(argv[i], ' ');
		if (splitted_args == NULL)
			exit(1);
		while (splitted_args[j])
		{

			// check if input is numeric
			// check if duplicate
		}
		add_node(env->stack_a, new_node(value));
	}
	return()
}

int	main(int argc, char **argv)
{
	t_env	*env;

	env = ft_calloc(1, sizeof(t_stack));
	if(!env)
		exit(1);
	env = parse_input(argv, env);
	return (0);
}
