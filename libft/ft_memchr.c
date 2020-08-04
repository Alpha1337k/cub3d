/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 15:45:38 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:57:11 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*str;
	unsigned long	x;

	str = (unsigned char *)s;
	x = 0;
	chr = c;
	while (x < n)
	{
		if (str[x] == chr)
			return ((void *)s);
		s++;
		x++;
	}
	return (0);
}
