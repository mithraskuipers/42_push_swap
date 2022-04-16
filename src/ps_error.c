/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/16 15:48:03 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/16 23:01:35 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
msg_exit()
Prints error statement to the standard error, followed by exiting the program.
*/

void msg_exit(char *s, int exit_code)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(exit_code);
}