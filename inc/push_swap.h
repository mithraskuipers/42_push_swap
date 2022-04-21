#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "../libft/libft.h"

typedef struct	s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}				t_stack;

void	ps_isvalid(char *s);
void	ps_addlast(t_stack **lst, t_stack *new);
void	ps_hasduplicates(t_stack *stack);
void	msg_exit(char *s, int exit_code);
void	print_list(t_stack *stack_a, t_stack *stack_b); /* temp */
t_stack	*ps_ll_getlast(t_stack *lst);
t_stack	*ps_new_element(int index, int value);
t_stack	*init_stack(char **argv, t_stack *stack);

/* push swap commands */
void	ps_swap(t_stack *lst);
int		ps_ll_len(t_stack *lst);
void	ps_swap_sync(t_stack *lst1, t_stack *lst2);
void	ps_push(t_stack **lst, t_stack *new);

#endif