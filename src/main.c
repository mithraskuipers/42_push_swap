/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/01 21:20:10 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
		exit(2);
	env = mk_calloc(1, sizeof(t_env));
	if ((!env))
		clean_and_exit("Error", env, 2);
	parse_input(argv, env);
	//print_forwards(&env->stack_a);
	check_input(env);
	//sort_stack(env);
	print_forwards(&env->stack_a);

	
	/* CLEAN */
	//swap_b(env); // CLEAN
	//push_a(env); // CLEAN
	//rotate_b(env); // CLEAN
	//rotate_s(env); // CLEAN? HOW CAN THAT BE WITH LEAK FROM ROTATE_A?
	//rrotate_a(env); // CLEAN

	/* LEAKS */
	//swap_a(env); // LEAK! OPGELOST??
	//swap_s(env);
	//push_b(env); // LEAK! OPGELOST?
	//rotate_a(env); // LEAK!
	//rrotate_b(env); // LEAK!
	//rrotate_s(env); // LEAK

	clean_and_exit("main ending clean_and_exit", env, 2);
	return (0);
}
