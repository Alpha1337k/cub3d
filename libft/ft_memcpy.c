/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 16:09:37 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:56:22 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			x;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	x = 0;
	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	while (x < n)
	{
		d[x] = s[x];
		x++;
	}
	return (dst);
}
