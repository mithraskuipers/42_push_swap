/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/30 08:29:33 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
getbinary = lambda x, n: format(x, 'b').zfill(n) ; getbinary(99, 8)
(cd tester2 && bash tester.sh .. 100 5)
vals=`python random_nums2.py` && ./push_swap $vals | ./checker_linux $vals
make && ARG="`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`" && ./push_swap $ARG | wc -l
vals=`python random_nums2.py` && ./push_swap $vals | ./checker_linux $vals
python3 pyviz.py `ruby -e "puts (0..50).to_a.shuffle.join(' ')"`
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
	print_forwards(&env->stack_b);
	//printf("\n");
	//print_forwards(&env->stack_b);
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
