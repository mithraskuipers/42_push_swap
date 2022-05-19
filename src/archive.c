/*
void	sort_5(t_stack **stack_a, t_stack **stack_b, int go)
{
	//sort_5(&env->stack_a, &env->stack_b, 1);
	int	index;

	index = get_idx_for_value(stack_a, get_min(stack_a));
	if ((index + 1) == 5)
		rrotate_a(stack_a);
	else
	{
		while (index)
		{
			rotate_a(stack_a);
			index--;
		}
	}
	push_b(stack_a, stack_b);
	if (go == 1)
	{
		sort_5(stack_a, stack_b, 0);
		sort_3(stack_a);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);		
	}
}
*/

/*
void	sort_3_rev(t_stack **head)
{
	t_stack	*start;
	t_stack	*middle;
	t_stack	*end;
	
	start = (*head);
	middle = (*head)->next;
	end = (*head)->next->next;
	if (middle->value > start->value && start->value > end->value)
		swap_a(head);
	else if (end->value > middle->value && middle->value > start->value)
	{
		swap_a(head);
		rrotate_a(head);
	}
	else if (middle->value > end->value && end->value > start->value)
		rotate_a(head);
	else if (start->value > end->value && end->value > middle->value)
	{
		swap_a(head);
		rotate_a(head);
	}
	else if (end->value > start->value && start->value > middle->value)
		rrotate_a(head);
}
*/