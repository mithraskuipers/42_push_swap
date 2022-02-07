#include "push_swap.h"
#include "../stack_list/push_swap_stack.h"
#include "../../libft/libft.h"
#include "../get_next_line/get_next_line.h"

#include <stdio.h>

static void valid_input(char *s);
static t_stack *init_stack(char **argv, t_stack *stack);
static t_stack	*ps_list_new(int index, int value);
static void	ps_list_addlast(t_stack **lst, t_stack *new);
static t_stack	*ps_list_findlast(t_stack *lst);
static int	ps_list_findlen(t_stack *lst);

int		main(int argc, char **argv)
{
	int		nbrs;
	t_stack *a;
	t_stack *b;

	nbrs = 0;
	if (argc < 1)
		return (0);
	a = init_stack(argv, NULL);
	return (0);
}

// niet static want ga ik waarschijnlijk vaker gebruiken
void ps_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static void valid_input(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != '+')
			ps_error();
		if (s[i] == '-' && !ft_isdigit(s[i+1]))
			ps_error();
		i++;
	}
}

static t_stack *init_stack(char **argv, t_stack *stack)
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
			valid_input(split[nbr]);
			ps_list_addlast(&stack, ps_list_new(ps_list_findlen(stack), \
			ft_atoi(split[nbr])));
			nbr++;
		}
		arg++;
	}
	print_list(stack, 0);
}

static t_stack	*ps_list_new(int index, int value)
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

static void	ps_list_addlast(t_stack **lst, t_stack *new)
{
	t_stack	*final_element;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	final_element = ps_list_findlast(*lst);
	final_element->next = new;

}

static t_stack	*ps_list_findlast(t_stack *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

static int	ps_list_findlen(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}


static int check_duplicate(t_stack *stack)
{
	while (lst)
	{
		
	}
}

// ADD DUPLICATE CHECK









//static void	parse_numbers(int argc, char **argv);
//static char	**dp_clean(char **dp);

/*
static void	parse_numbers(int argc, char **argv)
{
	int	i;
	char	**numbers;
	i = 0;

	numbers = ft_split(argv[i], ' ');


	//dp_clean(numbers);
}

static char	**dp_clean(char **dp)
{
	int	i;

	i = 0;
	while ((dp[i]) && dp)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
	return (NULL);
}
*/