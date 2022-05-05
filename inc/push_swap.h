#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INTMIN -2147483648
# define INTMAX 2147483647

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "../libft/libft.h"

typedef struct	s_stack
{
	int	value;
	int	index;
	struct s_stack *next;
	struct s_stack *previous;
}				t_stack;

typedef struct	s_env
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_env;

t_stack	*create_new_node(int value, int index);
t_stack *pop_node_front(t_stack **head);
void	insert_node(t_stack **head, t_stack *new_node, int pos);
t_stack	*pop_node_back(t_stack **head);
int		n_nodes(t_stack **head);
void	remove_node(t_stack **head, int pos);
void	print_forwards(t_stack **head);
void	parse_input(char **argv, t_stack **head);
t_stack	*ps_new_element(int index, int value);
void	ps_addlast(t_stack **head, t_stack *new);

#endif