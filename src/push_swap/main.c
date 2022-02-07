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
void			ps_error(void);
static void 	print_list(t_stack *stack_a, t_stack *stack_b);
static void 	check_duplicate(t_stack *stack);

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

	return (0);
}

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
	int		current;
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = stack;
	tmp2 = stack;
	while (tmp1)
	{
		current = tmp1->value;
		match = 0;
		while (tmp2)
		{
			if (current == tmp2->value)
				match++;
			if (match > 1)
				ps_error();
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}