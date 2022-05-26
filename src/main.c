/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/26 21:44:14 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
count_bits() calls get_max_value() to find the largest value
in the linked list, and then uses bitwise shifting using the
right shift operator to count the number of bits required
to express that value in binary.
*/


int	count_bits(t_stack **head)
{
	int		max_bits;
	int		largest_val;

	max_bits = 0;
	largest_val = get_max_value(head);
	while ((largest_val >> max_bits) > 0)
		max_bits++;
	return (max_bits);
}


/*

*/

/*
void	radix(t_env *env)
{
	int		i;
	int		j;
	t_stack	*head_a;
	int		n_nodes_a;

	i = 0;
	n_nodes_a = n_nodes(&env->stack_a);
	while (i < count_bits(&env->stack_a))
	{
		j = 0;
		while (j < n_nodes_a)
		{
			head_a = *&env->stack_a;
			if (((head_a->index >> i) & 1) == 1)
				rotate_a(&env->stack_a);
			else
				push_b(&env->stack_a, &env->stack_b);
			j++;
		}
		while (n_nodes(&env->stack_b) > 0)
			push_a(&env->stack_a, &env->stack_b);
		i++;
	}
}
*/

/*
void	radix(t_env *env)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = env->stack_a;
	size = n_nodes(&env->stack_a);
	max_bits = count_bits(&env->stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *(&env->stack_a);
			if (((head_a->index >> i) & 1) == 1)
				rotate_a(&env->stack_a);
			else
				push_b(&env->stack_a, &env->stack_b);
		}
		while (n_nodes(&env->stack_b) != 0)
			push_a(&env->stack_a, &env->stack_b);
		i++;
	}
}
*/


void	sort_stack(t_env *env)
{
	int	stack_len;

	stack_len = n_nodes(&env->stack_a);
	if ((stack_len) == 2)
		sort_2(&env->stack_a);
	else if ((stack_len) == 3)
		sort_3(&env->stack_a);
	else if ((stack_len) == 4)
		sort_4(&env->stack_a, &env->stack_b);
	else if ((stack_len) == 5)
		sort_5(&env->stack_a, &env->stack_b);
	else if ((stack_len) == 6)
		sort_6(&env->stack_a, &env->stack_b);
	else
	{
		indexer(&env->stack_a);
		radix(env);
	}
}

void	check_input(t_env *env)
{
	if (ps_hasduplicates(&env->stack_a))
		msg_exit("Error", 2);
	if (ps_isordered(&env->stack_a))
		exit(2);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
		exit(2);
	env = ft_calloc(1, sizeof(t_env));
	if ((!env))
		msg_exit("Error", 2);
	parse_input(argv, env);
	check_input(env);
	sort_stack(env);
	//swap_a(&env->stack_a); // leak!
	//push_b(&env->stack_a, &env->stack_b); // leak!
	//swap_b(&env->stack_b); // ???
	//print_forwards(&env->stack_a);
	//system("leaks push_swap");
	//free (env);
	return (0);
}

/*
TODO: Eval tests
ARG="1 5 2 4 3" && ./push_swap $ARG | ./checker_linux $ARG
6 instructions! even less than 8

ARG=" 888 -2 11 -2093 5" && ./push_swap $ARG | ./checker_linux $ARG
ARG=" 888 -2 11 -2093 5" && ./push_swap $ARG | wc -l
10 instructions! no more than 12!
*/
