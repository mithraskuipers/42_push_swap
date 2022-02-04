#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}				t_stack;

#endif

void	print_list(t_stack *stack_a, t_stack *stack_b);