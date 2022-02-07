#include "push_swap.h"
#include "../stack_list/push_swap_stack.h"
#include "../../libft/libft.h"
#include "../get_next_line/get_next_line.h"

#include <stdio.h>

static void 	valid_input(char *s);
static t_stack 	*init_stack(char **argv, t_stack *stack);
static t_stack	*ps_list_new(int index, int value);
static void		ps_list_addlast(t_stack **lst, t_stack *new);
static t_stack	*ps_list_findlast(t_stack *lst);
static int		ps_list_findlen(t_stack *lst);
//static int 		check_duplicate(t_stack *stack);
static void 	print_list(t_stack *stack_a, t_stack *stack_b);

int		main(int argc, char **argv)
{
	int		nbrs;
	t_stack *a;
	t_stack *b;

	nbrs = 0;
	if (argc < 1)
		return (0);
	a = init_stack(argv, NULL);
	print_list(a, NULL);
	//check_duplicate(a);
	return (0);
}

//print_list(stack, 0);


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
	return (stack);
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


static void	print_list(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a)
		printf("List a NULL\n\n");
	else
	{
		printf("List a:\n");
		while (stack_a->next)
		{
			printf("%d=%d\n", stack_a->index, stack_a->value);
			stack_a = stack_a->next;
		}
		printf("%d=%d\n\n", stack_a->index, stack_a->value);
	}
	if (!stack_b)
		printf("List b NULL\n");
	else
	{
		printf("List b:\n");
		while (stack_b->next)
		{
			printf("%d=%d\n", stack_b->index, stack_b->value);
			stack_b = stack_b->next;
		}
		printf("%d=%d\n", stack_b->index, stack_b->value);
	}
	printf("\n---\n\n");
}

/*
static int check_duplicate(t_stack *stack)
{
	printf("%d", stack->value);
	t_stack	*tmp;

	while (stack->next)
	{

		tmp = stack->next;
		while (tmp)
		{
			if (tmp->value == stack->value)
				return (1);
			tmp = tmp->next;
		}

		printf("%d", stack->next);
		stack = stack->next;
	}
	return (0);
}
*/

/*
static void check_duplicate(t_list *stack)
{
	t_stack	*ptr;

	while (stack)
	{
		ptr = stack->next;
		while (ptr)
		{
			if (ptr->value == stack->value)
				return ;
			ptr = ptr->next;
		}
		stack = stack->next;
	}
	printf("HEYYY");
	return ;
	//return (1);
}
*/

/*
new_elem->index = index;
new_elem->value = value;
new_elem->next = NULL;
*/

/*
static int check_duplicate(t_stack *stack)
{
	int i;
	i = 0;
	while (stack.next != NULL)
	{
		
	}
}


// ADD DUPLICATE CHECK
// Maak nieuwe stack
// Iterate over iedere value obv index
// Plaats die 


*/



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