/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 15:27:24 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/31 00:39:10 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack	*ps_getlast_node(t_stack *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ps_addlast(t_stack **head, t_stack *new)
{
	t_stack	*final_element;

	if (!(*head))
	{
		*head = new;
		return ;
	}
	final_element = ps_getlast_node(*head);
	final_element->next = new;
}


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
			ps_addlast(&env->stack_a, create_new_node(val, -1));
			j++;
		}
		dp_clean_char(splitted_args);
		i++;
	}
}
