/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 15:27:24 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/01 21:20:03 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	parse_input(char **argv, t_env *env)
{
	int		i;
	int		j;
	int		val;
	char	**splitted_args;

	i = 1;
	while (argv[i])
	{
		splitted_args = ft_split(argv[i], ' ');
		if (splitted_args == NULL)
			exit(2);
		j = 0;
		while (splitted_args[j])
		{
			if ((mk_atoi(splitted_args[j], &val) == -1) || \
			(str_only_nbrs(splitted_args[j]) == 0))
				msg_exit("Error", 2);
			addnode_end(&env->stack_a, newnode(val, -1));
			j++;
		}
		dp_clean_char(splitted_args);
		i++;
	}
}
*/



static void	check_and_add(t_env *env, char *s)
{
	int		val;
	t_stack	*tmp;

	if ((mk_atoi(s, &val) == -1) || \
	(str_only_nbrs(s) == 0))
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
		printf("%s\n", split_args[j]);
		while (split_args[j])
		{
			check_and_add(env, split_args[j]);
			j++;
		}
		dp_clean_char(split_args);
		i++;
	}
	printf("\n\n\n");
}
