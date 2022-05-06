/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/06 21:10:12 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
visualization of operations
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
*/

#include "push_swap.h"

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

void	ps_addlast(t_stack **head, t_stack *new)
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

int	ps_nnodes(t_stack **lst)
{
	int	i;

	i = 0;
	while (*lst)
	{
		*lst = (*lst)->next;
		i++;
	}
	return (i);
}

t_stack	*ps_new_element(int index, int val)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (!(new_elem))
		return (NULL);
	new_elem->index = index;
	new_elem->val = val;
	new_elem->next = NULL;
	return (new_elem);
}

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






/* Function to insert a given node in the "sorted" linked list. Where
 * the insertion sort actually occurs.
 */ 
void insertIntoSorted(t_stack** sorted_ref,t_stack* new_node){
    t_stack* current; 
    /* Special case for the head end of the "sorted" */
    if ((*sorted_ref == NULL) || ((*sorted_ref)->val >= new_node->val)) 
    { 
        new_node->next = *sorted_ref; 
        *sorted_ref = new_node; 
    }
    /* Locate the node before the point of insertion */
    else
    {
        current = *sorted_ref; 
        while ((current->next!=NULL) && (current->next->val < new_node->val)){ 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
}

/* Function to sort a singly linked list using insertion sort */
void insertionSort(t_stack** head_ref){

    /* Initialize the sorted linked list */
    t_stack* sorted;
    sorted=NULL;

    /* Traverse the given linked list and insert every node to "sorted" */
    t_stack* current;
    current=*head_ref;
    while(current!=NULL){
        /* Store "next" for next iteration */ 
        t_stack* next;
        next=current->next;

        /*Insert "current" into the "sorted" linked list */
        insertIntoSorted(&sorted, current);

        /* Update "current" to the next node */
        current=next;
    }
    *head_ref=sorted;
}


/*
void	sort_2(t_stack **head)
{
	rotate_a(head);
	swap_a(head);
}
*/


void	sort_3(t_stack **head)
{
	t_stack	*start;
	t_stack	*middle;
	t_stack	*end;
	
	start = (*head);
	middle = (*head)->next;
	end = (*head)->next->next;
	if (middle->val < start->val && start->val < end->val)
		swap_a(head);
	else if (end->val < middle->val && middle->val < start->val)
	{
		swap_a(head);
		rrotate_a(head);
	}
	else if (middle->val < end->val && end->val < start->val)
		rotate_a(head);
	else if (start->val < end->val && end->val < middle->val)
	{
		swap_a(head);
		rotate_a(head);
	}
	else if (end->val < start->val && start->val < middle->val)
		rrotate_a(head);
}

int	main(int argc, char **argv)
{
	t_env	*env;
	(void)argc;
	env = ft_calloc(1, sizeof(t_stack));
	if (!env)
		exit(1);
	t_stack **new;
	new = ft_calloc(1, sizeof(t_stack));
	parse_input(argv, new);
	//reset_index(new);
	//insertionSort(new);
	if (ps_isordered(new))
		msg_exit("Error. Input is already ordered", 1);
	if (n_nodes(new) == 3)
		sort_3(new);
	print_forwards(new);
	/*
	if (ps_hasduplicates(new))
		msg_exit("Error. Input contains duplicates.", 1);

	*/
	return (0);
}
