
/*
count_bits() calls get_max_value() to find the largest value
in the linked list, and then uses bitwise shifting using the
right shift operator to count the number of bits required
to express that value in binary.
*/


int	count_bits(t_stack **head)
{
	int		max_bits;
	int		largest_val;

	max_bits = 0;
	largest_val = get_max_value(head);
	while ((largest_val >> max_bits) > 0)
		max_bits++;
	return (max_bits);
}


/*

*/


void	radix(t_env *env)
{
	int		i;
	int		j;
	t_stack	*head_a;
	int		n_nodes_a;

	i = 0;
	n_nodes_a = n_nodes(&env->stack_a);
	while (i < count_bits(&env->stack_a))
	{
		j = 0;
		while (j < n_nodes_a)
		{
			head_a = *&env->stack_a;
			if (((head_a->index >> i) & 1) == 1)
				rotate_a(&env->stack_a);
			else
				push_b(&env->stack_a, &env->stack_b);
			j++;
		}
		while (n_nodes(&env->stack_b) > 0)
			push_a(&env->stack_a, &env->stack_b);
		i++;
	}
}