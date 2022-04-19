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

int		linkedlist_len(t_stack *stack);
void	ps_isvalid(char *s);
void	ps_addlast(t_stack **lst, t_stack *new);
void	ps_hasduplicates(t_stack *stack);
void	msg_exit(char *s, int exit_code);
t_stack	*ps_list_findlast(t_stack *lst);
t_stack	*ps_new_element(int index, int value);
t_stack	*init_stack(char **argv, t_stack *stack);
void	print_list(t_stack *stack_a, t_stack *stack_b);

/* push swap commands */
void	ps_swap_a(t_stack **lst);


#endif