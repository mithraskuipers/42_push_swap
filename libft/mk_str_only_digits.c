/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mk_str_only_digits.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:22:20 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/26 17:42:31 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	mk_str_only_digits(char *s)
{
	int	i;
	
	i = 0;
	while(s[i])
	{
		if (ft_isdigit(s[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
