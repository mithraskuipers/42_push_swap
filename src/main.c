/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/28 15:16:56 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

make && python3 pyviz.py 50 17 29 6 28 39 48 47 46 30 38 36 25 37 27 24 31 11 20 26 5 16 22 0 13 1 3 19 33 49 7 15 35 14 2 23 4 41 32 10 9 44 40 42 8 45
python3 pyviz.py `ruby -e "puts (0..50).to_a.shuffle.join(' ')"`
50 17 29 6 28 39 48 47 46 30 38 36 25 37 27 24 31 11 20 26 5 16 22 0 13 1 3 19 33 49 7 15 35 14 2 23 4 41 32 10 9 44 34 43 12 18 21 40 42 8 45
./push_swap 50 17 29 6 28 39 48 47 46 30 38 36 25 37 27 24 31 11 20 26 5 16 22 0 13 1 3 19 33 49 7 15 35 14 2 23 4 41 32 10 9 44 34 43 12 18 21 40 42 8 45 | ./checker_Mac 50 17 29 6 28 39 48 47 46 30 38 36 25 37 27 24 31 11 20 26 5 16 22 0 13 1 3 19 33 49 7 15 35 14 2 23 4 41 32 10 9 44 34 43 12 18 21 40 42 8 45
make && ./push_swap 1 -2 3 -4 5 -6 7 -8 9 | wc -l
make fclean && git add . && git commit -m "norminette in progress" && git push
*/

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
