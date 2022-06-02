/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   msg_exit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 22:47:09 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/02 10:33:33 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	msg_exit(char *s, int exit_code)
{
	if (ft_strlen(s) != 0)
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(exit_code);
}
