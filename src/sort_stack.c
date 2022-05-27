/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/27 19:15:21 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/27 20:28:30 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_env *env)
{
	int	stack_len;

	stack_len = n_nodes(&env->stack_a);
	if ((stack_len) == 2)
		sort_2(env);
	else if ((stack_len) == 3)
		sort_3(env);
	else if ((stack_len) == 4)
		sort_4(env);
	else if ((stack_len) == 5)
		sort_5(env);
	else if ((stack_len) == 6)
		sort_6(env);
	else
		sort_big(env, 19);
}
