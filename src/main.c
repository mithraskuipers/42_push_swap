/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/01 23:14:40 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
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
*/

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
		exit(2);
	env = ft_calloc(1, sizeof(t_env));
	if ((!env))
		clean_and_exit("Error", env, 2);
	parse_input(argv, env);
	check_input(env);
	sort_stack(env);
	//system("leaks push_swap");
	clean_and_exit("", env, 2);
	return (0);
}
