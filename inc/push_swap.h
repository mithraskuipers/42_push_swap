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

void ps_isvalid(char *s);
void	ps_list_addlast(t_stack **lst, t_stack *new);
t_stack *init_stack(char **argv, t_stack *stack);
int linkedlist_len(t_stack *stack);
t_stack	*ps_list_findlast(t_stack *lst);
void ps_hasduplicates(t_stack *stack);
t_stack	*ps_list_new(int index, int value);
void msg_exit(char *s, int exit_code);

#endif