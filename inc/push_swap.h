#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INTMIN -2147483648
# define INTMAX 2147483647
# define TRUE 1
# define FALSE 0

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

t_stack *pop_node_front(t_stack **head);
void	parse_input(char **argv, t_env *env);
t_stack	*ps_new_element(int index, int value);
void	ps_addlast(t_stack **head, t_stack *new);
void	rotate_a(t_env *env);
void	rotate_b(t_env *env);
void	rotate_s(t_env *env);
void	swap_a(t_env *env);
void	swap_b(t_env *env);
void	swap_s(t_env *env);
void	rrotate_a(t_env *env);
void	rrotate_b(t_env *env);
void	rrotate_s(t_env *env);
void	push_a(t_env *env);
void	push_b(t_env *env);
int		get_idx_for_value(t_stack **head, int value);
int		get_min_value(t_stack **head);
int		get_max_value(t_stack **head);
void	simple_indexer(t_stack **head);
t_stack	*create_new_node(int val, int index);
void	add_node_back(t_stack **head, t_stack *new_node);
void	add_node_front(t_stack **head, t_stack *new_node);
void	insert_node(t_stack **head, t_stack *new_node, int pos);
t_stack	*pop_node_back(t_stack **head);
int		n_nodes(t_stack **head);
void	remove_node(t_stack **head, int pos);
void	print_forwards(t_stack **head);
int		ps_isordered(t_stack **head);
int		ps_hasduplicates(t_stack **head);
void	ps_isvalid(char *s);
void	msg_exit(char *s, int exit_code);
void	indexer(t_stack **head);
void	check_input(t_env *env);
void	sort_stack(t_env *env);

void	sort_2(t_env *env);
void	sort_3(t_env *env);
void	sort_4(t_env *env);
void	sort_5(t_env *env);
void	sort_6(t_env *env);
void	sort_big(t_env *env, int bucket_size);

void	put_minnode_upfront_a(t_env *env, int bucket_size);
void	put_maxnode_upfront_b(t_env *env);

#endif