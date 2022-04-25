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

#endif