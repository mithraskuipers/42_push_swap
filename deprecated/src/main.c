//https://github.com/mithraskuipers/libftpp.git


//make re && ./push_swap 1 5 8 10

#include "push_swap.h"



void	ps_swap_a(t_stack *stack);
void	ps_swap_sb(t_stack *stack);
void	ps_swap_ss(t_stack *ls1, t_stack *lst2);

void	ps_swap_a(t_stack *lst)
{
	t_stack	*tmp;
	int		val0;
	int		val1;

	if (ps_nnodes(lst) > 1)
	{
		tmp = lst;
		val0 = lst->value;
		val1 = lst->next->value;
		tmp->value = val1;
		tmp->next->value = val0;
	}
	ft_putstr_fd("sa\n", 2);
}

void	ps_swap_b(t_stack *lst)
{
	t_stack	*tmp;
	int		val0;
	int		val1;

	if (ps_nnodes(lst) > 1)
	{
		tmp = lst;
		val0 = lst->value;
		val1 = lst->next->value;
		tmp->value = val1;
		tmp->next->value = val0;
	}
	ft_putstr_fd("sb\n", 2);
}

void	ps_swap_s(t_stack *lst1, t_stack *lst2)
{
	t_stack	*tmp;
	int		val0;
	int		val1;

	if (ps_nnodes(lst1) > 1)
	{
		tmp = lst1;
		val0 = lst1->value;
		val1 = lst1->next->value;
		tmp->value = val1;
		tmp->next->value = val0;
	}
	if (ps_nnodes(lst2) > 1)
	{
		tmp = lst2;
		val0 = lst2->value;
		val1 = lst2->next->value;
		tmp->value = val1;
		tmp->next->value = val0;
	}
	ft_putstr_fd("ss\n", 2);
}

void	ps_rotate_a(t_stack **lst);


t_stack	*ps_lstlast(t_stack *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_stack	*ps_lstnew(int value, int index)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack) * 1);
	if (!(new_elem))
		return (NULL);
	new_elem->value = value;
	new_elem->index = index;
	new_elem->next = NULL;

	return (new_elem);
}

void	ps_rotate_a(t_stack **lst)
{
	t_stack	*head;

	head = *lst;
	if (ps_nnodes(*lst) > 1)
	{
		// vind het einde van lst
		// voeg daaraan nieuwe node toe
		// deze nieuwe node krijgt de value en index van de originele head
		ft_lstadd_back(lst, ps_new_element((*lst)->value, (*lst)->index));
		// let op gebruik van de *, gebruik haakjes
		(*lst) = (*lst)->next;
		free(head);
	}
}












int		main(int argc, char **argv)
{
	int		nbrs;
	t_stack	*a;
	//t_stack	*b;

	nbrs = 0;
	if (argc < 1)
		return (0);
	a = init_stack(argv, NULL);
	//b = init_stack(argv, NULL);
	printf("Stack size: %d\n", ps_nnodes(a));
	ps_swap_a(a);
	//print_list(a, a);
	//ps_rotate_a(&a);
	//system("leaks push_swap");
	//print_list(a, b);
}





/*
void	ft_rotate(t_stack **stack, int is_a)
{
	t_stack	*tmp;

	tmp = *stack;
	if (ft_lstsize(*stack) > 1)
	{
		ft_lstadd_back(stack, ft_lstnew((*stack)->value, (*stack)->index));
		(*stack) = (*stack)->next;
		free(tmp);
	}
	if (!is_a)
		write(1, "rb\n", 3);
	else if (is_a == 1)
		write(1, "ra\n", 3);
	else
		return ;
}
*/







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




/*
void	ft_rotate(t_stack **stack, int is_a)
{
	t_stack	*tmp;

	tmp = *stack;
	if (ft_lstsize(*stack) > 1)
	{
		ft_lstadd_back(stack, ft_lstnew((*stack)->value, (*stack)->index));
		(*stack) = (*stack)->next;
		free(tmp);
	}
	if (!is_a)
		write(1, "rb\n", 3);
	else if (is_a == 1)
		write(1, "ra\n", 3);
	else
		return ;
}
*/
