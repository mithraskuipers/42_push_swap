//https://github.com/mithraskuipers/libftpp.git


#include "push_swap.h"
#include "push_swap_stack.h"
#include "../libft/libft.h"

#include <stdio.h>

static void 	valid_input(char *s);
static t_stack 	*init_stack(char **argv, t_stack *stack);
static t_stack	*ps_list_new(int index, int value);
static void		ps_list_addlast(t_stack **lst, t_stack *new);
static t_stack	*ps_list_findlast(t_stack *lst);
static int		ps_list_findlen(t_stack *lst);
void			ps_error(void);
static void 	print_list(t_stack *stack_a, t_stack *stack_b);
static void 	check_duplicate(t_stack *stack);
//static int		check_ordered(t_stack *stack);
//static void		algorithms(t_stack *stack);
static int 		stack_size(t_stack *stack);
//static void		2nbr_algorithm(*stack);
//static void		3nbr_algorithm(*stack);

int		main(int argc, char **argv)
{
	int		nbrs;
	t_stack *a;
	t_stack *b;

	nbrs = 0;
	if (argc < 1)
		return (0);
	a = init_stack(argv, NULL);
	printf("Stack size: %d\n", stack_size(a));
	// if (!(check_ordered(a)))
	// algorithms(a);
	// printf("Stack size: %d\n", stack_size(a));
	// printf("NOT ORDERED!");
	// clean_memory();
	print_list(a, NULL);
	return (0);
}

int	swap(t_stack *stack, char *cmd_s)
{
	int	i;
	t_stack	*temp;

	temp = stack;
	if (temp && temp->next)
	{
		i = temp->value;
		temp->value = temp->next->value;
		temp->next->value = i;
		//ft_putendl(s);
		return (1);
	}
	return (0);
}

/*
static void 2nbr_algorithm(t_stack *stack)
{
	//
}

static void 3nbr_algorithm(t_stack *stack)
{
	//
}
*/

/*
static void	algorithms(t_stack *stack)
{
	if (stack_size(stack) == 2) // als niet in order
	{
		2nbr_algorithm(stack);
	}
	else if (stack_size(stack) == 3)
	{
		3nbr_algorithm(stack);
	}
	while (!(is_in_order(stack)))
	{
		if (stack->a_size == 2)
		{
			swap_a(stack);
			write(1, "sa\n", 3);
		}
		else if (stack->a_size == 3)
			three_numbers(stack);
		else if (is_decrescent(stack))
			decrescent_algorithm(stack);
		else if (stack->a_size == 5)
		{
			five_numbers(stack);
			three_numbers(stack);
			push_a(stack);
			push_a(stack);
			write(1, "pa\npa\n", 6);
		}
		else
			algorithm(stack);
	}
}
*/

void ps_error(void) // niet static want vaak gebruiken
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
	check_duplicate(stack);
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

static void check_duplicate(t_stack *stack)
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
				ps_error();
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

/*
static int check_ordered(t_stack *stack)
{
	int		previous;
	t_stack	*tmp;

	tmp = stack;
	previous = tmp->value;
	while (tmp)
	{
		if (tmp->value < previous)
		{
			return (0);
		}
		previous = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}
*/

static int stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

