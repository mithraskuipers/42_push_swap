/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   msg_error.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 22:32:18 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/30 22:32:49 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
msg_exit()
Prints error statement to the standard error, followed by exiting the program.
*/

void	msg_exit(char *s, int exit_code)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(exit_code);
}
