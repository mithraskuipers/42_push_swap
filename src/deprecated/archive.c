

void	reset_index(t_stack **head)
{
	t_stack	*tmp;
	int	i;

	tmp = *head;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}


t_stack	*create_new_node(int val, int index)
{
	t_stack	*node;

	node = malloc(1 * sizeof(t_stack));
	node->value = val;
	node->index = index;
	node->next = NULL;
	return (node);
}


void	remove_first_node(t_stack **head)
{
	t_stack	*new_head;

	new_head = (*head)->next;
	(*head) = new_head;
}

t_stack	*ret_last_node(t_stack **head)
{
	t_stack	*last_node;
	last_node = (*head);

	while (last_node)
		(last_node) = last_node->next;
	return (last_node);
}

void	lststack_add_back(t_stack **head, t_stack *new)
{
	while((*head)->next)
		(*head) = (*head)->next;
	(*head)->next = new;
}

t_stack	*ps_getlast_node(t_stack *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}












void	remove_node(t_stack **head, int pos)
{
	t_stack	*edge_left;
	t_stack *right;

	edge_left = *head;
	if (pos > n_nodes(head))
		pos = n_nodes(head);
	if (pos == 0)
		(*head) = (*head)->next;
	else
	{
		while ((pos > 1) && (edge_left->next))
		{
			edge_left = edge_left->next;
			pos--;
		}
		right = edge_left->next->next;
		edge_left->next = right;
	}
}





/*
ps_isvalid()
Checks whether user input is numeric. If not, exit the program.
It checks every character in the string for being either a digit, space, 
minus/plus sign character. If not, it prints an error statement and exits the
program with exit code 1.
*/

void	ps_isvalid(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != '+')
			msg_exit("Error", 2);
		if (s[i] == '-' && !ft_isdigit(s[i+1]))
			msg_exit("Error", 2);
		i++;
	}
}

void	simple_indexer(t_stack **head)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *head;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

/*
void	addnode_end(t_stack **head, t_stack *new)
{
	t_stack	*final_element;

	if (!(*head))
	{
		*head = new;
		return ;
	}
	final_element = ps_getlast_node(*head);
	final_element->next = new;
}
*/


int		get_max_value(t_stack **head)
{
	int		tmp_max;
	t_stack	*tmp;
	
	tmp = *head;
	tmp_max = tmp->value;
	while (tmp)
	{
		if (tmp_max < tmp->value)
			tmp_max = tmp->value;
		tmp = tmp->next;
	}
	return (tmp_max);
}



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



