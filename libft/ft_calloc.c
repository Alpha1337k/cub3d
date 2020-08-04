/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:43:46 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:56:52 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned long x;
	unsigned char *rval;

	rval = 0;
	x = 0;
	if (nitems == 0)
		nitems = 1;
	if (size == 0)
		size = 1;
	rval = (unsigned char *)malloc(nitems * size);
	if (rval == 0)
		return (0);
	while (x < nitems * size)
	{
		rval[x] = 0;
		x++;
	}
	return ((void *)rval);
}
