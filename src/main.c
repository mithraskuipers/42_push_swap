/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/27 21:14:21 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
python3 pyviz.py `ruby -e "puts (0..500).to_a.shuffle.join(' ')"`
make && ./push_swap 1 -2 3 -4 5 -6 7 -8 9 | wc -l
*/

void	put_node_upfront(t_env *env, int max_val, int bucket_size)
{
	int	x;
	int	y;

	while (1)
	{
		if (max_val == INTMIN)
			return ;
		if ((max_val - bucket_size) <= env->stack_a->value && \
		(max_val + bucket_size) >= env->stack_a->value)
			return ;
		x = get_idx_for_value(&env->stack_a, max_val);
		y = n_nodes(&env->stack_a) / 2;
		if (x < y)
			rotate_a(env);
		else
			rrotate_a(env);
	}
}

void	put_node_upfront_b(t_env *env, int min_val)
{
	int	x;
	int	y;
	int	atoi;

	while (TRUE)
	{
		atoi = env->stack_b->value;
		if (atoi == min_val)
			return ;
		x = get_idx_for_value(&env->stack_b, min_val);
		if (env->stack_b->next && env->stack_b->next->value == min_val)
			swap_b(env);
		else
		{
			y = n_nodes(&env->stack_b) / 2;
			if (x < y)
				rotate_b(env);
			else
				rrotate_b(env);
		}
	}
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
	return (0);
}

/*
//swap_a(&env->stack_a); // leak!
//push_b(&env->stack_a, &env->stack_b); // leak!
//swap_b(&env->stack_b); // ???
//print_forwards(&env->stack_a);
//system("leaks push_swap");
//free (env);

TODO:
Make norm
Clean up prototypes, all require only env, not both stacks
Clean up memory leaks
*/
