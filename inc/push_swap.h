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

void	rotate_a(t_stack **head);
void	rotate_b(t_stack **head);
void	rotate_s(t_stack **head1, t_stack **head2);
void	swap_a(t_stack **head);
void	swap_b(t_stack **head);
void	swap_s(t_stack **head1, t_stack **head2);
void	rrotate_a(t_stack **head);
void	rrotate_b(t_stack **head);
void	rrotate_s(t_stack **head1, t_stack **head2);
void	push_a(t_stack **head1, t_stack **head2);
void	push_b(t_stack **head1, t_stack **head2);

void	add_node_back(t_stack **head, t_stack *new_node);
void	add_node_front(t_stack **head, t_stack *new_node);

int		ps_isordered(t_stack **stack);
int		ps_hasduplicates(t_stack **head);
void	msg_exit(char *s, int exit_code);


#endif

