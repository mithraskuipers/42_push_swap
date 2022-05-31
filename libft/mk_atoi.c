/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mk_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 11:37:24 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/31 20:55:32 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	mk_atoi(char *s, int *nbr)
{
	int		i;
	int		sign;
	long	value;

	i = 0;
	while (iswhitespace(s[i]))
		i++;
	value = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		value = (value * 10) + (s[i] - '0');
		if (value > INTMAX || value < INTMIN)
			return (-1);
		i++;
	}
	*nbr = (int)value * sign;
	return (0);
}
