/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_radix.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/27 19:44:56 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/07 14:51:58 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sort_radix() implements the radix sorting algorithm using the pre-indexed nodes.
Here, the indices are simply a set of numbers that are used to order the 
collection of values from smallest to largest. As a consequence, when the nodes 
are sorted on their index value, the user inputted list of numbers will be
sorted from smallest to largest. The reason why I applied radix to the indices
instead of values is that it makes radix more efficient when working with
non-contiguous sequences of randomized numbers. By definition, working with
indices means that you work with contiguous sequences of (randomized) numbers
(i.e. there are no "gaps" between the numbers; e.g., 0-1-2-3-4 vs 0-5-11-39-83).
Basically, the algorithm works by repeatedly iterating over each node in stack a
until stack a is sorted in ascending order on each node's index, and
consequently on its value. During each iteration, stack a becomes a little bit
more sorted, starting with first sorting on the least significant digits (i.e.
right-most digit). This is accomplished using the bitwise right shift operator 
'>>'. Whenever the right shift operator has been called on an integer (here our
current node's index value) the result is returned in 8-bit binary format. Next,
a comparsion is made to find out whether the right-most bit of this result is
1 or 0. If it is 1, it considers the current node's index to be large and sends
it to the bottom of stack a using rotate_a(). Else, it considers it to be small
and sends it to the top of stack b using push_b(). When all nodes have been
parsed, everything from stack b is send to the top of stack a using push_a().
The result is now that the (relatively) smaller nodes are located at the top of
stack a, getting a step closer to having stack a sorted in ascending order. This
process is repeated until stack a is sorted.
*/

void	sort_radix(t_env *env)
{
	int	len;
	int	node;
	int	significance;
	int	bitshifted_val;

	significance = 0;
	len = n_nodes(&env->stack_a);
	while (isordered(&env->stack_a) == 0)
	{
		node = 0;
		while (node < len)
		{
			bitshifted_val = (env->stack_a)->index >> significance;
			if ((bitshifted_val & 1) == 1)
				rotate_a(env);
			else
				push_b(env);
			node++;
		}
		while (n_nodes(&env->stack_b) > 0)
			push_a(env);
		significance++;
	}
}
