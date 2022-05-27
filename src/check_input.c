/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/27 19:25:54 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/27 19:26:08 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(t_env *env)
{
	if (ps_hasduplicates(&env->stack_a))
		msg_exit("Error", 2);
	if (ps_isordered(&env->stack_a))
		exit(2);
}
