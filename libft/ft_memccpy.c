/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 17:43:41 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:57:05 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			x;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	ch;

	ch = (unsigned char)c;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	x = 0;
	while (x != n)
	{
		d[x] = s[x];
		if (s[x] == ch)
			return (d + x + 1);
		x++;
	}
	return (0);
}
