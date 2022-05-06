/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 15:27:24 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/06 15:32:13 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_input(char **argv, t_stack **head)
{
	int		i;
	int		j;
	char	**splitted_args;
	int		value;
	
	i = 1;
	while (argv[i])
	{
		splitted_args = ft_split(argv[i], ' ');
		if (splitted_args == NULL)
			exit(1);
		j = 0;
		while (splitted_args[j])
		{
			if (mk_atoi(splitted_args[j], &value) == -1)
			{
				msg_exit("Error. mk_atoi failed.", 1);
			}
			ps_addlast(head, ps_new_element(-1, value));
			j++;
		}
		dp_clean_char(splitted_args);
		i++;
	}
}