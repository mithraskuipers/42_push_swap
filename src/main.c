//https://github.com/mithraskuipers/libftpp.git


//make re && ./push_swap 1 5 8 10

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int		nbrs;
	t_stack *a;
	t_stack *b;

	nbrs = 0;
	if (argc < 1)
		return (0);
	a = init_stack(argv, NULL);
	b = init_stack(argv, NULL);
	printf("Stack size: %d\n", ps_ll_len(a));
	// if (!(ps_isordered(a)))
	// algorithms(a);
	// printf("Stack size: %d\n", ps_ll_len(a));
	// printf("NOT ORDERED!");
	// clean_memory();
	//int z = ps_ll_len(a);
	//ft_putnbr_fd(z, 2);
	ps_swap_sync(a, b);
	ps_addlast(&a, b); //
	print_list(a, b);
	return (0);
}

/*
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
*/

/*
void 2nbr_algorithm(t_stack *stack)
{
	//
}

void 3nbr_algorithm(t_stack *stack)
{
	//
}
*/

/*
void	algorithms(t_stack *stack)
{
	if (ps_ll_len(stack) == 2) // als niet in order
	{
		2nbr_algorithm(stack);
	}
	else if (ps_ll_len(stack) == 3)
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

void	print_list(t_stack *stack_a, t_stack *stack_b)
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
