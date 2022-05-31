/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_radix.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/27 19:44:56 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/31 11:38:29 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Intuitvely, sort_radix() implements the radix sorting algorithm. The twist is 
here that the algorithm has been used on the indices of the nodes instead of the
values (i.e. user input). Here, the indices are simply a set of numbers that are
used to order the collection of values from smallest to largest. As a 
consequence, when the nodes are sorted on their index value, the used inputted
list of numbers has been sorted from smallest to largest. The reason why I
applied radix to the indices instead of values is that it makes radix more
efficient when working with non-contiguous sequences of randomized numbers. 
By definition, working with indices means that you work with contiguous 
sequences of randomized numbers (i.e. there are no "gaps" between the numbers;
e.g., 0-1-2-3-4, vs 0-5-11-39-83).

Basically, here the algorithm works by sorting the nodes on the least
significant digit (i.e. units) of the value that they hold. When that process
has been performed on all nodes, the process is repeated but now for the 
second-least significant digit (i.e. tens), etc., until all digits have been
processed. These digit comparisons are accomplished using the bitwise right
shift operator '>>'. Whenever the right shift operator has been called on an
integer the result is returned in 8-bit format.
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
