/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mk_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 13:46:11 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/01 13:46:13 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*mk_calloc(size_t count, size_t size)
{
	void			*ptr;
	size_t			i;
	size_t			len;
	unsigned char	*b_uc;
	unsigned char	c;

	ptr = malloc(count * size);
	if (!(ptr))
		return (NULL);
	i = 0;
	len = count * size;
	b_uc = (unsigned char *)ptr;
	c = 0;
	while (i < len)
	{
		b_uc[i] = c;
		i++;
	}
	return (ptr);
}
