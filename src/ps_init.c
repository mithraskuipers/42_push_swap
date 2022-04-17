/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_init.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/16 15:46:59 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/17 11:02:20 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
init_stack()
Initializes user input by creating a linked list and checking for duplicates.
Note that this function able to parse string literals placed inbetween separate
argument values.
*/

t_stack *init_stack(char **argv, t_stack *stack)
{
	int	arg;
	int nbr;
	char **split;

	arg = 1;
	while (argv[arg])
	{
		split = ft_split(argv[arg], ' ');
		if (!split)
			exit (EXIT_FAILURE);
		nbr = 0;
		while (split[nbr])
		{
			ps_isvalid(split[nbr]);
			ps_list_addlast(&stack, ps_new_element(linkedlist_len(stack), \
			ft_atoi(split[nbr])));
			nbr++;
		}
		arg++;
	}
	ps_hasduplicates(stack);
	return (stack);
}

/*
ps_hasduplicates()
Checks whether the linked list contains duplicate values.
If so, it calls msg_exit() which exits the program.
*/

void ps_hasduplicates(t_stack *stack)
{
	int		match;
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = stack;
	tmp2 = stack;
	while (tmp1)
	{
		match = 0;
		while (tmp2)
		{
			if (tmp1->value == tmp2->value)
				match++;
			if (match > 1)
				msg_exit("Error", 1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

/*
ps_isvalid()
Checks whether user input is numeric. If not, exit the program.
It checks every character in the string for being either a digit, space, 
minus/plus sign character. If not, it prints an error statement and exits the
program with exit code 1.
*/

void ps_isvalid(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != '+')
			msg_exit("Error", 1);
		if (s[i] == '-' && !ft_isdigit(s[i+1]))
			msg_exit("Error", 1);
		i++;
	}
}

/*
ps_new_element()
Creates a new element for the linked list, conform my own setup format.
It allocates memory for the new element, and sets its index and value values
to what has been inputted by the user.
*/

t_stack	*ps_new_element(int index, int value)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (!(new_elem))
		return (NULL);
	new_elem->index = index;
	new_elem->value = value;
	new_elem->next = NULL;
	return (new_elem);
}
