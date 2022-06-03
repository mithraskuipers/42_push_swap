/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/03 13:41:45 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
		exit(1);
	env = ft_calloc(1, sizeof(t_env));
	if ((!env))
		clean_and_exit("Error", env, 1);
	parse_input(argv, env);
	check_input(env);
	sort_stack(env);
	clean_and_exit("", env, 0);
	return (0);
}
