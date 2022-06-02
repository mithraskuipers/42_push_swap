/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 15:27:24 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/02 11:49:08 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_and_add(t_env *env, char *s)
{
	int		val;
	t_stack	*tmp;

	if ((mk_atoi(s, &val) == -1) || (!str_only_nbrs(s)))
		clean_and_exit("Error", env, 2);
	tmp = newnode(val, -1);
	addnode_end(&env->stack_a, tmp);
}

void	parse_input(char **argv, t_env *env)
{
	int		i;
	int		j;
	char	**split_args;

	i = 1;
	while (argv[i])
	{
		split_args = ft_split(argv[i], ' ');
		if (split_args == NULL)
			clean_and_exit("Error", env, 2);
		j = 0;
		while (split_args[j])
		{
			check_and_add(env, split_args[j]);
			j++;
		}
		dp_clean_char(split_args);
		i++;
	}
}
