/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 12:37:27 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:56:31 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			x;
	unsigned char	*ed;
	unsigned char	ch;

	ch = (unsigned char)c;
	ed = (unsigned char *)b;
	x = 0;
	while (x < n)
	{
		ed[x] = ch;
		x++;
	}
	return (b);
}
